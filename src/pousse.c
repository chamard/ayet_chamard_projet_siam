#include "plateau_siam.h"
#include "joueur.h"
#include "plateau_modification.h"
#include "condition_victoire_partie.h"
#include "piece_siam.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "coordonnees_plateau.h"


int poussee_etre_valide(const plateau_siam* plateau,int x, int y,orientation_deplacement orientation_pousse)
{
  //préconditions
  assert(plateau!=NULL);
  assert(orientation_etre_integre_deplacement(orientation_pousse));
  assert(coordonnees_etre_dans_plateau(x,y));

 /*
  * algorthime
  * 
  * 1. Si l'orientation de pousse et différente de l'orientation de la piece alors pousse invalide
  * 2. Si l'orientation des pieces n'est pas compatible avec une poussé alors pousse invalide
  * 3. Si la confrontation est impossible (rochers vs pousseurs) alors pousse invalide
  * 4. Sinon pousse valide
  * 
  */

  const piece_siam* piece_p;
  piece_p=plateau_obtenir_piece_info(plateau,x,y);
   
  if(orientation_pousse!=piece_p->orientation)
    return 0;
   
  float force_poussee=1;
  int x1=x,y1=y;
   
  switch(orientation_pousse)
  {
  case haut:
    while(piece_p->type!=case_vide && y1<NBR_CASES && force_poussee>0)
    {
      if (piece_p->orientation==haut)
  	     force_poussee+=1;
      if (piece_p->orientation==bas)
  	     force_poussee-=1;
      if (piece_p->type==rocher)
    	   force_poussee-=0.99;

      piece_p=plateau_obtenir_piece_info(plateau,x,++y1);
    }

  break;
  case bas:
    while(piece_p->type!=case_vide && y1>=0 && force_poussee>0)
    {
      if (piece_p->orientation==haut)
  	     force_poussee-=1;
      if (piece_p->orientation==bas)
  	     force_poussee+=1;
      if (piece_p->type==rocher)
  	     force_poussee-=0.99;

      piece_p=plateau_obtenir_piece_info(plateau,x,--y1);
    }
  break;
  case droite:
    while(piece_p->type!=case_vide && x1<NBR_CASES && force_poussee>0)
    {
      if (piece_p->orientation==droite)
          force_poussee+=1;
      if (piece_p->orientation==gauche)
          force_poussee-=1;
      if (piece_p->type==rocher)
          force_poussee-=0.99;

      piece_p=plateau_obtenir_piece_info(plateau,++x1,y);
    }
  break;
  case gauche:
    while(piece_p->type!=case_vide && x1>=0 && force_poussee>0)
    {
      if (piece_p->orientation==droite)
         force_poussee=force_poussee-1;
      if (piece_p->orientation==gauche)
         force_poussee=force_poussee+1;
      if (piece_p->type==rocher)
         force_poussee=force_poussee-0.99;

      piece_p=plateau_obtenir_piece_info(plateau,--x1,y);
    }
  break;
  default:
    puts("probleme");
  }

  if(force_poussee>0)
    return 1;
  else
    return 0;
}

plateau_siam poussee_realiser(plateau_siam* plateau, int x, int y,type_piece type ,orientation_deplacement orientation,condition_victoire_partie* condition)
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
   * 1. Vérifie si le coup est gagnant
   * 2. On effectue la pousse
   *      1. Si la derniere pièce poussée n'est pas sur la bordure on la pousse sur la case vide suivante
   *      2. Si le coup n'est pas une insertion on met une case vide
   * 
   */
 
   
  int x1=x,y1=y;

  //On trouve la derniere case poussée
  do
  {
  coordonnees_appliquer_deplacement(&x1,&y1,orientation);
  }while(plateau_obtenir_piece_info(plateau,x1,y1)->type!=case_vide || coordonnees_etre_bordure_plateau(x1,y1)==0);
  int x2=x1,y2=y1;

  //1- Il y a un gagnant si la dernière case poussée est un rocher sur une bordure
  if(coordonnees_etre_bordure_plateau(x1,y1) && plateau_obtenir_piece(plateau,x1,y1)->type==rocher)
  {
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
    }while(condition->victoire!=1);
  }

  //2-  On effectue la pousse
  //2.1- Si la derniere pièce poussée n'est pas sur la bordure on se place sur la case vide suivante
  if(coordonnees_etre_bordure_plateau(x2,y2)==0)
   {
    coordonnees_appliquer_deplacement(&x2,&y2,orientation);
   }
  x1=x2;
  y1=y2;
  do
  {  
   coordonnees_appliquer_deplacement(&x1,&y1,orientation_inverser(orientation));
   plateau_obtenir_piece(plateau,x2,y2)->type = plateau_obtenir_piece_info(plateau,x1,y1)->type;
   plateau_obtenir_piece(plateau,x2,y2)->orientation = plateau_obtenir_piece_info(plateau,x1,y1)->orientation;
   coordonnees_appliquer_deplacement(&x2,&y2,orientation_inverser(orientation));
  }while((x==x2 && y==y2) == 0);
  
  plateau_obtenir_piece(plateau,x,y)->orientation=orientation;
  plateau_obtenir_piece(plateau,x,y)->type=type;

  //2.2- Si le coup n'est pas une insertion on met une case vide
  if(coordonnees_etre_bordure_plateau(x,y)!=0)
   {
    coordonnees_appliquer_deplacement(&x,&y,orientation_inverser(orientation));
    plateau_obtenir_piece(plateau,x,y)->orientation=aucune_orientation;
    plateau_obtenir_piece(plateau,x,y)->type=case_vide;
   }

   //post vérification
   assert(plateau_etre_integre(plateau));

   return *plateau;
}