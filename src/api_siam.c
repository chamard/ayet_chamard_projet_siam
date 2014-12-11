#include "api_siam.h"
#include "plateau_modification.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

coup_jeu api_siam_tenter_introduire_nouvelle_piece_si_possible(jeu_siam* jeu,
                                                               int x,int y,
                                                               orientation_deplacement orientation)
{
    assert(jeu!=NULL);
       
    coup_jeu coup;
    coup_jeu_initialiser(&coup);
    if(plateau_modification_introduire_piece_etre_possible(&jeu->plateau,x,y,jeu_obtenir_type_animal_courant(jeu),orientation)==0)
    {
      coup.valide=0;
      return coup; 
    }
    
    plateau_modification_introduire_piece(&jeu->plateau,x,y,jeu_obtenir_type_animal_courant(jeu),orientation,&coup.condition_victoire);
    coup.valide=1;
    
    return coup;
}



coup_jeu api_siam_tenter_deplacer_piece_si_possible(jeu_siam* jeu,
                                                    int x,int y,
                                                    orientation_deplacement deplacement,
                                                    orientation_deplacement orientation)
{
    //coder cette fonction
    coup_jeu coup;
    coup_jeu_initialiser(&coup);
    return coup;
}



coup_jeu api_siam_tenter_changer_orientation_piece_si_possible(jeu_siam* jeu,int x,int y,orientation_deplacement orientation)
{
    //coder cette fonction
    coup_jeu coup;
    coup_jeu_initialiser(&coup);
    return coup;
}
