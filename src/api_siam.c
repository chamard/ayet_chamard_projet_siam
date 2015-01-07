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
    jeu_changer_joueur(jeu);   
    return coup;
}



coup_jeu api_siam_tenter_deplacer_piece_si_possible(jeu_siam* jeu,
                                                    int x,int y,
                                                    orientation_deplacement deplacement,
                                                    orientation_deplacement orientation)
{ 
    coup_jeu coup;
    coup_jeu_initialiser(&coup);

    if(jeu_verifier_type_piece_a_modifier(jeu,x,y)==0)
    {
      coup.valide=0;
      return coup; 
    }

    if(plateau_modification_deplacer_piece_etre_possible(&jeu->plateau,x,y,deplacement,orientation)==0)
    {
      coup.valide=0;
      return coup; 
    }
    else{
      plateau_modification_deplacer_piece(&jeu->plateau,x,y,deplacement,orientation,&coup.condition_victoire);                    
      coup.valide=1;
      jeu_changer_joueur(jeu);  
      return coup;
    }
}



coup_jeu api_siam_tenter_changer_orientation_piece_si_possible(jeu_siam* jeu,int x,int y,orientation_deplacement orientation)
{
    assert(jeu!=NULL);
    assert(jeu_etre_integre(jeu));
   
    coup_jeu coup;
    coup_jeu_initialiser(&coup);
    
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
      coup.valide=1;
      jeu_changer_joueur(jeu);  
      
     return coup;
}
