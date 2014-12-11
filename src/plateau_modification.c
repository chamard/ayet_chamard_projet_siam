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
