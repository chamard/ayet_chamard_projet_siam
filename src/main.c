
#include "piece_siam.h"
#include <stdio.h>


void test_lancer(){
  puts("***********************");
  puts("TESTS DES FONCTIONS RECENTES");
  puts("***********************");
  test_type_etre_integre();
  puts("***********************");
  test_orientation_etre_integre_deplacement();
  puts("***********************");
  test_orientation_caractere_etre_integre();
  puts("***********************");
  test_orientation_correspondre_caractere();
  puts("***********************");
}


int main()
{  

    type_piece type=elephant;
    
    printf("%d\n", type);
    int est_ce_un_elephant = (type==elephant);
    int est_ce_un_rocher = (type==rocher);
    printf("%d %d\n", est_ce_un_elephant, est_ce_un_rocher);
    
    const char* nom_du_type=type_nommer(type);
    printf("Le type est un %s. \n", nom_du_type);
    
    printf("Le type est un %s. \n", type_nommer(rocher));
    
    test_lancer();
    
       return 0;
}