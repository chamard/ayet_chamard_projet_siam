#include "plateau_siam.h"
#include "joueur.h"
#include "plateau_modification.h"
#include "condition_victoire_partie.h"
#include "pousse.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int poussee_etre_valide(const plateau_siam* plateau,int x, int y,orientation_deplacement orientation_pousse)
{
   
 /*
  * algorthime
  * 
  * 1. Si l'orrientation de pousse et différente de l'orientation de la piece alors pousse invalide
  * 2. Si l'orriantation des pieces n'est pas compatible avec une poussé alors pousse invalide
  * 3. Si la confrontation est impossible (rochers vs pousseurs) alors pousse invalide
  * 4. Sinon pousse valide
  * 
  */
  return 0;
}

plateau_siam poussee_realiser(plateau_siam* plateau, int x, int y,type_piece type ,orientation_deplacement orientation,condition_victoire_partie* condition)
{
  /*
   * algorthime 
   * 
   * 1. Vérifie si la pousse est possible
   * 2 .Si possible alors effectue la pousse
   * 
   */
 
  return *plateau;
}