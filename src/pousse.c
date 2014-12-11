#include "plateau_siam.h"
#include "joueur.h"
#include "plateau_modification.h"
#include "condition_victoire_partie.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int poussee_etre_valide(const plateau_siam* plateau,int x, int y,orientation_deplacement orientation_pousse)
{
  
 /* On ne peut pousser que dans la direction correspondant à l'orientation de l'animal.
  * 
  * 
  * On peut pousser autant d'objets(rocher ou animal) se succédant dans une direction X 
  * si les animaux ont la même orientation X, se succéde, sont  aligné 
  * et ou l'un des animaux pousseurs touche l'objet et que le compte est positif.
  * 
  * Un rocher vaut -1  
  * Un animal dans la bonne direction X vaut 1
  * Un animal dans la direction tangente a X vaut 0
  * Un animal dans la bonne direction -X vaut -1
  * 
  * 
  * 
  * 
  * 
  * 
  * 
  */
  return 0;
}

plateau_siam poussee_realiser(plateau_siam* plateau, int x, int y,type_piece type ,orientation_deplacement orientation,condition_victoire_partie* condition)
{
  
 
  return *plateau;
}