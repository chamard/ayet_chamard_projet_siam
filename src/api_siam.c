#include "api_siam.h"
#include "plateau_modification.h"
#include "joueur.h"
#include "plateau_siam.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

coup_jeu api_siam_tenter_introduire_nouvelle_piece_si_possible(jeu_siam* jeu,
                                                               int x,int y,
                                                               orientation_deplacement orientation)
{
    //coder cette fonction
    coup_jeu coup;
    coup_jeu_initialiser(&coup);
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
    assert(jeu!=NULL);
    assert(jeu_etre_integre(jeu));
   
    coup_jeu coup;
    coup_jeu_initialiser(&coup);
    
    coup.valide=1;
    
    
    piece_siam* Piece=plateau_obtenir_piece(&jeu->plateau,x,y);
    
     if(jeu_verifier_type_piece_a_modifier(jeu,x,y)==0)
     {
	coup.valide=0;
	return coup;
     }
     
     if(orientation_etre_integre(orientation)==0)
      {
	coup.valide=0;
	return coup;
      }
      
      if(plateau_modification_changer_orientation_piece_etre_possible(&jeu->plateau,x,y,orientation) == 0)
      {
	coup.valide=0;
	return coup;
      }
      
            
      plateau_modification_changer_orientation_piece(&jeu->plateau,x,y,orientation);
      
     return coup;
}
