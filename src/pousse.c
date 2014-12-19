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
  assert(plateau!=NULL);
  assert(orientation_pousse!=aucune_orientation);
  assert(coordonnees_etre_dans_plateau(x,y));
  assert(piece_etre_animal(plateau_obtenir_piece_info(plateau,x,y)));
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
   int piece_suivante=0;
 
 switch(orientation_pousse)
 {
   
   case haut:
        
     while(piece_p->type!=case_vide ||y+piece_suivante<NBR_CASES-1||force_poussee!=0)
     {
      piece_p=plateau_obtenir_piece_info(plateau,x,y+piece_suivante);
      if (piece_p->orientation==haut)
	force_poussee=force_poussee+1;
      if (piece_p->orientation==bas)
	force_poussee=force_poussee-1;
      if (piece_p->type==rocher)
	force_poussee=force_poussee-0.99;
      piece_suivante++;
     piece_p=plateau_obtenir_piece_info(plateau,x,y+piece_suivante);
     }
     if(force_poussee>1)
       
       return 1;
     if(force_poussee<=1)
       return 0;
      
   case bas:
     
     while(piece_p->type!=case_vide ||y-piece_suivante>0||force_poussee!=0)
     {
      piece_p=plateau_obtenir_piece_info(plateau,x,y-piece_suivante);
      if (piece_p->orientation==haut)
	force_poussee=force_poussee-1;
      if (piece_p->orientation==bas)
	force_poussee=force_poussee+1;
      if (piece_p->type==rocher)
	force_poussee=force_poussee-0.99;
      piece_suivante++;
     piece_p=plateau_obtenir_piece_info(plateau,x,y-piece_suivante);
  
     }
     if(force_poussee>1)
       return 1;
     if(force_poussee<=1)
       return 0;
           
   case gauche:
          
     while(piece_p->type!=case_vide ||x+piece_suivante<NBR_CASES-1||force_poussee!=0)
     {
      piece_p=plateau_obtenir_piece_info(plateau,x+piece_suivante,y);
      if (piece_p->orientation==gauche)
	force_poussee=force_poussee+1;
      if (piece_p->orientation==droite)
	force_poussee=force_poussee-1;
      if (piece_p->type==rocher)
	force_poussee=force_poussee-0.99;
      piece_suivante++;
     piece_p=plateau_obtenir_piece_info(plateau,x+piece_suivante,y);
     }
     
     if(force_poussee>1)
       return 1;
     if(force_poussee<=1)
       return 0;
     
   case droite:
            
     while(piece_p->type!=case_vide ||x-piece_suivante>0||force_poussee!=0)
     {
      piece_p=plateau_obtenir_piece_info(plateau,x-piece_suivante,y);
      if (piece_p->orientation==gauche)
	force_poussee=force_poussee-1;
      if (piece_p->orientation==droite)
	force_poussee=force_poussee+1;
      if (piece_p->type==rocher)
	force_poussee=force_poussee-0.99;
      piece_suivante++;
     piece_p=plateau_obtenir_piece_info(plateau,x-piece_suivante,y);
     }
     
     if(force_poussee>1)
       return 1;
     if(force_poussee<=1)
       return 0;
     
   default:
     break;
     
 }
 
  return 0;
}

plateau_siam poussee_realiser(plateau_siam* plateau, int x, int y,type_piece type ,orientation_deplacement orientation,condition_victoire_partie* condition)
{
  /*
   * algorthime 
   * 
   * 1. Vérifie si la pousse est possible
   * 2 .Si possible alors effectue la pousse
   * 
   * 
   */
  assert(condition!=NULL);
  assert(orientation_etre_integre(orientation));
  assert(poussee_etre_valide(plateau,x,y,orientation));
   
  int x1=x,y1=y,cpt=0;
  
  do
  {
  coordonnees_appliquer_deplacement(&x,&y,orientation);
  cpt=cpt+1;
  }while(plateau_obtenir_piece_info(plateau,x,y)->type!=case_vide || coordonnees_etre_bordure_plateau(x,y)==0);
  
  coordonnees_appliquer_deplacement(&x1,&y1,orientation_inverser(orientation));
  
  int x11=x1,y11=y1;
  int xx=x,yy=y;
  
  while(plateau_obtenir_piece(plateau,xx,yy)->type==rocher)
  {
    if (plateau_obtenir_piece_info(plateau,x11,y11)->type==elephant)
    {
	condition->joueur=0;
	condition->victoire=1;
    }
     if (plateau_obtenir_piece_info(plateau,x11,y11)->type==rhinoceros)
    {
	condition->joueur=1;
	condition->victoire=1;
    }
     coordonnees_appliquer_deplacement(&xx,&yy,orientation_inverser(orientation));
     coordonnees_appliquer_deplacement(&x11,&y11,orientation_inverser(orientation));
  }
  
  do
  {
   cpt=cpt-1;
   plateau_obtenir_piece(plateau,x,y)->type = plateau_obtenir_piece_info(plateau,x1,y1)->type;
   plateau_obtenir_piece(plateau,x,y)->orientation = plateau_obtenir_piece_info(plateau,x1,y1)->orientation;
   coordonnees_appliquer_deplacement(&x1,&y1,orientation_inverser(orientation));
   coordonnees_appliquer_deplacement(&x,&y,orientation_inverser(orientation));
  }while(cpt!=0);
  
  plateau_obtenir_piece(plateau,x1,y1)->orientation=aucune_orientation;
  plateau_obtenir_piece(plateau,x1,y1)->type=case_vide;

  return *plateau;
}