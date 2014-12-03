#include "plateau_modification.h"
#include "piece_siam.h"
#include "plateau_siam.h"
#include "jeu_siam.h"
#include "api_siam.h"
#include "mode_interactif.h"

#include <stdio.h>

void test_lancer(){
  puts("***********************");
  puts("TESTS DES FONCTIONS RECENTES");
  puts("***********************");
  test_plateau_etre_integre();
  puts("***********************");
  test_piece_etre_integre();
  puts("***********************");
  test_piece_etre_un_animal();
  puts("***********************");
  test_jeu_verifier_type_piece_a_modifier();
  puts("***********************");
  test_plateau_modification_changer_orientation_piece_etre_possible();
}

int main()
{  

    /*plateau_siam plateau;
    plateau_initialiser(&plateau);
        
    piece_siam* p1=plateau_obtenir_piece(&plateau,2,3);
    
    piece_afficher(p1);puts(" ");
    p1->type=rocher;
    piece_afficher(p1);puts(" ");
    
    plateau_afficher(&plateau);puts(" ");
    
    */
    
    test_lancer();
    mode_interactif_lancer();
       
    
    
       return 0;
}
