#include "plateau_siam.h"
#include "joueur.h"
#include "plateau_modification.h"
#include "condition_victoire_partie.h"
#include "piece_siam.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "coordonnees_plateau.h"


int poussee_etre_valide(const plateau_siam* plateau,int x, int y,orientation_deplacement orientation)
{
  //préconditions
  assert(plateau!=NULL);
  assert(orientation_etre_integre_deplacement(orientation));
  assert(coordonnees_etre_dans_plateau(x,y));

 /*
  * algorthime
  * 
  * 1. Si l'orientation de pousse est différente de l'orientation de la piece alors pousse invalide
  * 2. Si l'orientation des pieces n'est pas compatible avec une poussé alors pousse invalide
  * 3. Si le rapport de force est défavorable (rochers vs pousseurs) alors pousse invalide
  * 4. Sinon pousse valide
  * 
  */
  const piece_siam* piece_p;
  float force_poussee=1;
  int x1 = x,
      y1 = y;

  coordonnees_appliquer_deplacement(&x,&y,orientation_inverser(orientation));
  if(coordonnees_etre_dans_plateau(x,y))
  {
    piece_p = plateau_obtenir_piece_info (plateau,x,y);
    if(piece_p -> orientation != orientation)
      return 0;
  }
   
  while (coordonnees_etre_dans_plateau(x1,y1) && plateau_exister_piece(plateau,x1,y1) && force_poussee>0)
  {
    piece_p = plateau_obtenir_piece_info (plateau,x1,y1);
    
    if(piece_p -> type == rocher){
        force_poussee -= 0.9;
    }
    else{
      if(piece_p -> orientation == orientation_inverser(orientation))
	  force_poussee -= 1;
      if(piece_p -> orientation == orientation)
	  force_poussee += 1;
    }
    coordonnees_appliquer_deplacement(&x1,&y1,orientation);
  }

  if(force_poussee>0)
    return 1;
  else
    return 0;
}

void poussee_realiser(plateau_siam* plateau, int x, int y,type_piece type ,orientation_deplacement orientation,condition_victoire_partie* condition)
{
  //préconditions
  assert(plateau!=NULL);
  assert(orientation_etre_integre(orientation));
  assert(poussee_etre_valide(plateau,x,y,orientation));
  assert(type_etre_animal(type));
  assert(condition!=NULL);

  /*
   * algorthime 
   * 
   * 1. Vérifie si le coup est gagnant et trouver la derniere case à pousser
   * 2. On effectue la pousse
   *      1. Si la derniere pièce poussée n'est pas sur la bordure on la pousse sur la case vide suivante
   *      2. Si le coup n'est pas une insertion on met une case vide
   * 
   */
   
  int x1=x,
      y1=y;

  //On trouve la derniere case poussée
  do
  {
    coordonnees_appliquer_deplacement(&x1,&y1,orientation);
  }while(coordonnees_etre_dans_plateau(x1,y1) && plateau->piece[x1][y1].type != case_vide);
  int x2=x1,
      y2=y1,
      x3=x1,
      y3=y1;
      
  coordonnees_appliquer_deplacement(&x1,&y1,orientation_inverser(orientation));

  //1- Il y a un gagnant si la dernière case poussée est un rocher sur une bordure
  int vic=0;
  if( coordonnees_etre_dans_plateau(x2,y2)==0 && plateau_obtenir_piece(plateau,x1,y1)->type==rocher)
  {
    vic=1;
    do
    {
      coordonnees_appliquer_deplacement(&x1,&y1,orientation_inverser(orientation));
      if(plateau_obtenir_piece_info(plateau,x1,y1)->orientation==orientation)
      {

        if (plateau_obtenir_piece_info(plateau,x1,y1)->type==elephant)
        { 
          condition->joueur=0;
          condition->victoire=1;
        }
        if (plateau_obtenir_piece_info(plateau,x1,y1)->type==rhinoceros)
        {
          condition->joueur=1;
          condition->victoire=1;
        }
      }
    }while(condition->victoire!=1 && coordonnees_etre_dans_plateau(x1,y1));
  }
  if(vic==1 && condition->victoire==0)
  {
    if (type==elephant)
    { 
        condition->joueur=0;
        condition->victoire=1;
    }
    else
    {
        condition->joueur=1;
        condition->victoire=1;
    }
  }

  //2-  On effectue la pousse
  //2.1- Si la derniere pièce poussée n'est pas sur la bordure on se place sur la case vide suivante
  if( coordonnees_etre_dans_plateau(x3,y3)==0)
  {
    coordonnees_appliquer_deplacement(&x3,&y3,orientation_inverser(orientation));
  }
  x1=x3;
  y1=y3;
  
  while((x==x3 && y==y3) == 0)
  { 
   coordonnees_appliquer_deplacement(&x1,&y1,orientation_inverser(orientation));
   plateau_obtenir_piece(plateau,x3,y3)->type = plateau_obtenir_piece_info(plateau,x1,y1)->type;
   plateau_obtenir_piece(plateau,x3,y3)->orientation = plateau_obtenir_piece_info(plateau,x1,y1)->orientation;
   coordonnees_appliquer_deplacement(&x3,&y3,orientation_inverser(orientation));
  }

  plateau_obtenir_piece(plateau,x,y)->orientation=orientation;
  plateau_obtenir_piece(plateau,x,y)->type=type;

  //2.2- Si le coup n'est pas une insertion on met une case vide
  coordonnees_appliquer_deplacement(&x,&y,orientation_inverser(orientation));
  if(coordonnees_etre_dans_plateau(x,y))
   {
    plateau_obtenir_piece(plateau,x,y)->orientation=aucune_orientation;
    plateau_obtenir_piece(plateau,x,y)->type=case_vide;
   }

   //post vérification
   assert(plateau_etre_integre(plateau));
}