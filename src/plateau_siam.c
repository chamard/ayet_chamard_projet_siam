#include "plateau_siam.h"
#include "entree_sortie.h"
#include "piece_siam.h"
#include "jeu_siam.h"
#include "api_siam.h"
#include "mode_interactif.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


void plateau_initialiser(plateau_siam* plateau)
{
    // Initialise l'ensemble des cases du plateau a piece_vide
    // sauf les 3 cases du milieu avec un rocher (2,1), (2,2) et (2,3)
    //
    // L'etat de l'echiquier initial est le suivant:
    //
    // [4] *** | *** | *** | *** | *** |
    // [3] *** | *** | *** | *** | *** |
    // [2] *** | RRR | RRR | RRR | *** |
    // [1] *** | *** | *** | *** | *** |
    // [0] *** | *** | *** | *** | *** |
    //     [0]   [1]   [2]   [3]   [4]
    //


    int kx=0;
    for(kx=0;kx<NBR_CASES;++kx)
    {
        int ky=0;
        for(ky=0;ky<NBR_CASES;++ky)
        {
            piece_siam* piece=plateau_obtenir_piece(plateau,kx,ky);
            assert(piece!=NULL);

            if(ky==2 && (kx>=1 && kx<=3) )
                piece_definir_rocher(piece);
            else
                piece_definir_case_vide(piece);
        }
    }

    assert(plateau_etre_integre);
}

int plateau_etre_integre(const plateau_siam* plateau)
{
    assert(plateau!=NULL);
    
    int compteur_rocher=0,compteur_rhino=0,compteur_elephant=0,compteur_vide=0;
    int kx=0;
    
    
    for(kx=0;kx<NBR_CASES;++kx)
    {
        int ky=0;
	for(ky=0;ky<NBR_CASES;++ky)
	{
	  const piece_siam* piece=plateau_obtenir_piece_info(plateau,kx,ky);
	  assert(piece!=NULL);
	  
	  switch(piece->type)
	  {
	    case elephant:
	      compteur_elephant++;
	      break;
	    case rhinoceros:
	      compteur_rhino++;
	      break;
	    case rocher:
	      compteur_rocher++;
	      break;
	    case case_vide:
	      compteur_vide++;
	      break;
	   }
	 }	  
    }
    printf("%d %d %d",compteur_rocher,compteur_elephant,compteur_rhino);
    if(compteur_rocher>3||compteur_elephant>5||compteur_rhino>5)
    {
      return 0;
    }
    
    return 1;
}

piece_siam* plateau_obtenir_piece(plateau_siam* plateau,int x,int y)
{
    assert(plateau!=NULL);
    assert(coordonnees_etre_dans_plateau(x,y));

    piece_siam* piece=&(plateau->piece[x][y]);

    return piece;
}

const piece_siam* plateau_obtenir_piece_info(const plateau_siam* plateau,int x,int y)
{
    assert(plateau!=NULL);
    assert(coordonnees_etre_dans_plateau(x,y));

    const piece_siam* piece=&(plateau->piece[x][y]);

    return piece;
}


int plateau_denomber_type(const plateau_siam* plateau,type_piece type)
{
    assert(plateau!=NULL);
    //Algorithme:
    //
    //Initialiser compteur <-0
    //pour toutes les cases du tableau
    //	si case courante est type du tableau
    //		Incremente compteur
    //Renvoie compteur
    
    int compteur=0;
    int kx=0;
    
    
    for(kx=0;kx<NBR_CASES;++kx)
    {
        int ky=0;
	for(ky=0;ky<NBR_CASES;++ky)
	{
	  const piece_siam* piece=plateau_obtenir_piece_info(plateau,kx,ky);
	  assert(piece!=NULL);
	  
	  if(piece->type==type)
	    compteur++;	  
	}	  
    }
    return compteur;
}

int plateau_exister_piece(const plateau_siam* plateau,int x,int y)
{
   if(plateau->piece[x][y].type==case_vide)
     return 0;
   else
     return 1;
}

void plateau_afficher(const plateau_siam* plateau)
{
    assert(plateau!=NULL);

    //utilisation d'une fonction generique d'affichage
    // le parametre stdout permet d'indiquer que l'affichage
    // est realise sur la ligne de commande par defaut.
    entree_sortie_ecrire_plateau_pointeur_fichier(stdout,plateau);

}

void test_plateau_etre_integre()
{
    puts("test_plateau_etre_integre");
    
    plateau_siam plateau_test;
    plateau_initialiser(&plateau_test);
    
    piece_siam* p1=plateau_obtenir_piece(&plateau_test,0,0);
    p1->type=rhinoceros;
    p1=plateau_obtenir_piece(&plateau_test,0,1);
    p1->type=rhinoceros;
    p1=plateau_obtenir_piece(&plateau_test,0,2);
    p1->type=rhinoceros;
    p1=plateau_obtenir_piece(&plateau_test,0,3);
    p1->type=rhinoceros;
    p1=plateau_obtenir_piece(&plateau_test,0,4);
    p1->type=rhinoceros;
    p1=plateau_obtenir_piece(&plateau_test,4,0);
    p1->type=elephant;
    p1=plateau_obtenir_piece(&plateau_test,4,1);
    p1->type=elephant;
    p1=plateau_obtenir_piece(&plateau_test,4,2);
    p1->type=elephant;
    p1=plateau_obtenir_piece(&plateau_test,4,3);
    p1->type=elephant;
    p1=plateau_obtenir_piece(&plateau_test,4,4);
    p1->type=elephant;
    
    puts("Nous testons ce plateau :");
    plateau_afficher(&plateau_test);puts(" ");
    if(plateau_etre_integre(&plateau_test)==1)
      puts("***OK***");
    
    p1=plateau_obtenir_piece(&plateau_test,1,2);
    p1->type=elephant;   
    puts("Nous testons ce plateau :");
    plateau_afficher(&plateau_test);puts(" ");
    if(plateau_etre_integre(&plateau_test)!=1)
      puts("***KO***");
    
    p1->type=rhinoceros;
    puts("Nous testons ce plateau :");
    plateau_afficher(&plateau_test);puts(" ");
    if(plateau_etre_integre(&plateau_test)!=1)
      puts("***KO***");
    
    p1->type=rocher;
    puts("Nous testons ce plateau :");
    plateau_afficher(&plateau_test);puts(" ");
    if(plateau_etre_integre(&plateau_test)!=1)
      puts("***KO***");  
}

void test_plateau_exister_piece(){
   puts("test_plateau_exister_piece");
  
  plateau_siam plateau_test;
  plateau_initialiser(&plateau_test);
  
  if(plateau_exister_piece(&plateau_test,0,0)==0)
      puts("***OK***");
  
  if(plateau_exister_piece(&plateau_test,2,2)==1)
      puts("***OK***"); 
}