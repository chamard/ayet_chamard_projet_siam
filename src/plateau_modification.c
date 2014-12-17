#include "plateau_modification.h"
#include "coordonnees_plateau.h"
#include "piece_siam.h"


#include <assert.h>
#include <stdlib.h>
#include <stdio.h>



int plateau_modification_introduire_piece_etre_possible(const plateau_siam* plateau,
                                                        int x,int y,
                                                        type_piece type,
                                                        orientation_deplacement orientation)
{
    //preconditions
    assert(plateau!=NULL);
    assert(coordonnees_etre_bordure_plateau(x,y));
    assert(plateau_etre_integre(plateau));
    assert(orientation_etre_integre_deplacement(orientation));
 

    //Algorithme:
    //
    // 1- Vérifie si on peut ajouter une piece dans le jeu
    //
    // 2- Vérifie si la case est vide 
    //
    
    if(plateau_denombrer_type(plateau,type)==5)
      return 0;
    if(plateau_obtenir_piece_info(plateau,x,y)->type!=case_vide)
      return 0;
    else
      return 1;
}


void plateau_modification_introduire_piece(plateau_siam* plateau,
                                           int x,int y,
                                           type_piece type,
                                           orientation_deplacement orientation,
                                           condition_victoire_partie* condition_victoire)
{
    //preconditions
    assert(plateau!=NULL);
    assert(coordonnees_etre_bordure_plateau(x,y));
    assert(plateau_etre_integre(plateau));
    assert(orientation_etre_integre_deplacement(orientation));
    assert(plateau_modification_introduire_piece_etre_possible(plateau,x,y,type,orientation));
    
    //introduction piece
    piece_siam* piece=plateau_obtenir_piece(plateau,x,y);
    piece->orientation=orientation;
    piece->type=type;
    
    //Post conditions
    assert(piece_etre_animal(piece));
    assert(plateau_etre_integre(plateau)); 
     
}


int plateau_modification_changer_orientation_piece_etre_possible(plateau_siam* plateau,int x0,int y0,orientation_deplacement orientation)
{
  
   assert(plateau!=NULL);

    //Algorithme:
    //
    // 1- Verification conditions necessaires:
    //    * Coordonnees doivent etre dans le plateau
    //    * Coordonnees doivent designer une piece
    //    * L'orientation doit etre un deplacement
    //  Sinon renvoie 0
    //
    // 2- Verification du changement d'orientation:
    //    Si orientation actuelle differente de l'orientation souhaitee
    //      Alors renvoie 1
    //    Sinon renvoie 0
    //

    if(coordonnees_etre_dans_plateau(x0,y0)==0)
        return 0;
    if(orientation_etre_integre_deplacement(orientation)==0)
        return 0;
    if(plateau_exister_piece(plateau,x0,y0)==0)
        return 0;

    //verification orientation differente
    const piece_siam* piece=plateau_obtenir_piece_info(plateau,x0,y0);
    if(piece->orientation==orientation)
        return 0;

    return 1;
}



void plateau_modification_changer_orientation_piece(plateau_siam* plateau,int x0,int y0,orientation_deplacement orientation)
{
    //preconditions
    assert(plateau!=NULL);
    assert(coordonnees_etre_dans_plateau(x0,y0));
    assert(plateau_exister_piece(plateau,x0,y0)==1);
    assert(orientation_etre_integre_deplacement(orientation));

    assert(plateau_modification_changer_orientation_piece_etre_possible(plateau,x0,y0,orientation));

    //changement d'orientation
    piece_siam* piece=plateau_obtenir_piece(plateau,x0,y0);
    piece->orientation=orientation;


    //Post conditions
    assert(piece_etre_animal(piece));
    assert(plateau_etre_integre(plateau));
         
}


int plateau_modification_deplacer_piece_etre_possible(const plateau_siam* plateau,
                                                      int x0,int y0,
                                                      orientation_deplacement direction_deplacement,
                                                      orientation_deplacement orientation)
{
 
    //preconditions
    assert(plateau!=NULL);
    assert(plateau_etre_integre(plateau));
    assert(orientation_etre_integre_deplacement(orientation));
    assert(orientation_etre_integre_deplacement(direction_deplacement));
    assert(coordonnees_etre_dans_plateau(x0,y0));


    //Algorithme:
    //
    if(direction_deplacement==haut)
      y0++;
    if(direction_deplacement==bas)
      y0--;
    if(direction_deplacement==droite)
      x0++;
    if(direction_deplacement==gauche)
      x0--;
    
    if(coordonnees_etre_dans_plateau(x0,y0)==0)
      return 0;
    
    if(plateau_obtenir_piece_info(plateau,x0,y0)->type!=case_vide)
      return 0;
    else
      return 1;
}


void plateau_modification_deplacer_piece(plateau_siam* plateau,
                                         int x0,int y0,
                                         orientation_deplacement direction_deplacement,
                                         orientation_deplacement orientation_final,
                                         condition_victoire_partie* condition_victoire)
{
   //preconditions
   assert(plateau!=NULL);
   assert(plateau_etre_integre(plateau));
   assert(orientation_etre_integre_deplacement(orientation_final));   
   assert(orientation_etre_integre_deplacement(direction_deplacement)); 
   assert(piece_etre_animal(&plateau->piece[x0][y0]));
   assert(plateau_modification_deplacer_piece_etre_possible(plateau,x0,y0,direction_deplacement,plateau->piece[x0][y0].orientation));
   
   //Algorithme
   
   
   int x1=x0,y1=y0;
   
   if(direction_deplacement==haut)
      y1++;
   if(direction_deplacement==bas)
      y1--;
   if(direction_deplacement==droite)
      x1++;
   if(direction_deplacement==gauche)
      x1--;
   
   piece_siam* piece=plateau_obtenir_piece(plateau,x0,y0);
   piece_siam* piece_fin=plateau_obtenir_piece(plateau,x1,y1);

   piece_fin->orientation=orientation_final;
   piece->orientation=aucune_orientation;
   
   piece_fin->type=piece->type;
   piece->type=aucune_orientation;
   
   //Post conditions
   assert(plateau_etre_integre(plateau));
   assert(piece_etre_animal(&plateau->piece[x1][y1]));
     
     
}

void test_plateau_modification_changer_orientation_piece_etre_possible()
{
    puts("plateau_modification_changer_orientation_piece_etre_possible");
    
    plateau_siam plateau_test;
    plateau_initialiser(&plateau_test);

   
    plateau_test.piece[0][0].type=rhinoceros;
    plateau_test.piece[0][0].orientation=haut;
    if(plateau_modification_changer_orientation_piece_etre_possible(&plateau_test,0,0,bas)==1)
	puts("***OK***");
    if(plateau_modification_changer_orientation_piece_etre_possible(&plateau_test,0,0,haut)==0)
	puts("***OK***");
    if(plateau_modification_changer_orientation_piece_etre_possible(&plateau_test,0,1,bas)==0)
	puts("***OK***");   
}
