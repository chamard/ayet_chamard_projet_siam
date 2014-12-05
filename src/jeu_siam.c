#include "jeu_siam.h"
#include "joueur.h"

#include "entree_sortie.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


int jeu_etre_integre(const jeu_siam* jeu)
{
    assert(jeu!=NULL);

    //verification du joueur integre
    const int joueur=jeu->joueur;
    if(joueur_etre_integre(joueur)==0)
        return 0;

    //verification du plateau integre
    const plateau_siam* plateau=&jeu->plateau;
    if(plateau_etre_integre(plateau)==0)
        return 0;

    return 1;
}


void jeu_initialiser(jeu_siam* jeu)
{

    assert(jeu!=NULL);

    //initialise le plateau
    //initialise le joueur

    plateau_initialiser(&jeu->plateau);
    jeu->joueur=0;
}





void jeu_changer_joueur(jeu_siam* jeu)
{
    assert(jeu!=NULL);
    assert(jeu_etre_integre(jeu));

    joueur_changer(&jeu->joueur);

    assert(jeu_etre_integre(jeu));

}


int jeu_verifier_type_piece_a_modifier(const jeu_siam* jeu,int x,int y)
{
    assert(jeu!=NULL);
    if (jeu->joueur==0 && ((jeu->plateau).piece[x][y]).type==elephant)
    return 1;
    if (jeu->joueur==1 && ((jeu->plateau).piece[x][y]).type==rhinoceros) 
    return 1;
    
    return 0;
}

void jeu_afficher(const jeu_siam* jeu)
{
    assert(jeu!=NULL);

    //utilisation d'une fonction generique avec affichage sur
    //  la ligne de commande.
    entree_sortie_ecrire_jeu_pointeur_fichier(stdout,jeu);
}



type_piece jeu_obtenir_type_animal_courant(const jeu_siam* jeu)
{
     assert(jeu!=NULL);
     if(jeu->joueur==0)
       return elephant;
     if(jeu->joueur==1)
      return rhinoceros;
     return -1;
}

void test_jeu_verifier_type_piece_a_modifier()
{
  puts("test jeu_verifier_type_piece_a_modifier");
  const jeu_siam* jeu;
  
  jeu_siam jeu1;
  jeu1.joueur=0;
  jeu=&jeu1;
	(jeu1.plateau).piece[2][3].type=elephant;
  
		    if (jeu_verifier_type_piece_a_modifier(jeu,2,3)==1)
		      puts("OK");
		      
		    if (jeu_verifier_type_piece_a_modifier(jeu,3,2)==0)
		      puts("OK");
		    
	(jeu1.plateau).piece[2][3].type=rhinoceros;
		    
		    if (jeu_verifier_type_piece_a_modifier(jeu,2,3)==0)
		      puts("OK");
   
   jeu_siam jeu2;
   jeu2.joueur=1;
   jeu=&jeu2;
	(jeu2.plateau).piece[2][3].type=elephant;
   
		    if (jeu_verifier_type_piece_a_modifier(jeu,2,3)==0)
		      puts("OK");
		    
	(jeu2.plateau).piece[2][3].type=rhinoceros;
		    
		    if (jeu_verifier_type_piece_a_modifier(jeu,2,3)==1)
		      puts("OK");
}
