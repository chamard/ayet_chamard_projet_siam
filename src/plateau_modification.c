#include "plateau_modification.h"
#include "coordonnees_plateau.h"


#include <assert.h>
#include <stdlib.h>
#include <stdio.h>



int plateau_modification_introduire_piece_etre_possible(const plateau_siam* plateau,
                                                        int x,int y,
                                                        type_piece type,
                                                        orientation_deplacement orientation)
{
    return 1; //coder cette fonction
}


void plateau_modification_introduire_piece(plateau_siam* plateau,
                                           int x,int y,
                                           type_piece type,
                                           orientation_deplacement orientation,
                                           condition_victoire_partie* condition_victoire)
{
    //coder cette fonction
}


int plateau_modification_changer_orientation_piece_etre_possible(plateau_siam* plateau,int x0,int y0,orientation_deplacement orientation)
{
  
  assert(plateau!=NULL);
  if (piece_etre_animal(&(plateau->piece[x0][y0]))==0)
       return 0;
  if(plateau->piece[x0][y0].orientation==orientation)
       return 0;
  return 1;
}



void plateau_modification_changer_orientation_piece(plateau_siam* plateau,int x0,int y0,orientation_deplacement orientation)
{
    if (plateau_modification_changer_orientation_piece_etre_possible(plateau,x0,y0,orientation)==1)
      plateau->piece[x0][y0].orientation=orientation;
         
}


int plateau_modification_deplacer_piece_etre_possible(const plateau_siam* plateau,
                                                      int x0,int y0,
                                                      orientation_deplacement direction_deplacement,
                                                      orientation_deplacement orientation)
{
    return 1;
}


void plateau_modification_deplacer_piece(plateau_siam* plateau,
                                         int x0,int y0,
                                         orientation_deplacement direction_deplacement,
                                         orientation_deplacement orientation_final,
                                         condition_victoire_partie* condition_victoire)
{
    //coder cette fonction
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
