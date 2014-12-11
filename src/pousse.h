/**
 * **************************************************
 * **************************************************
 *   _____ _____  ______   _
 *  / ____|  __ \|  ____| | |
 * | |    | |__) | |__    | |    _   _  ___  _ __
 * | |    |  ___/|  __|   | |   | | | |/ _ \| '_ \
 * | |____| |    | |____  | |___| |_| | (_) | | | |
 *  \_____|_|    |______| |______\__, |\___/|_| |_|
 *                                __/ |
 *                               |___/
 * **************************************************
 * **************************************************
 *
 * Role general de ce fichier
 * --------------------------------------------------------------
 * 
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 *
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 *
 */

/**
 * 
 Fonction poussee_etre_valide:
 *
 *************************
 *
 *Verifie si il est possible de realiser une poussee qui debute 
 *aux coordonnees(x,y) dans l'orientation  definie.
 *Note: Les coordonnees (x,y) designent la premiere piece rencontree 
 *dans la poussee.
 * Necessite:
 *-Un pointeur non NULL vers un plateau integre non modifiable. 
 * - Deux coordonnees entieres (x,y) designant une piece non 
 * vide integre du plateau. 
 * - Une  orientation de poussee designant une direction integre.  
 *
 * Garantie: 
 * - Un retour valant 1 si la poussee est possible. 
 * - Un retour valant 0 sinon. 
 **/ 

int poussee_etre_valide(const plateau_siam* plateau,int x, int y,orientation_deplacement orientation_pousse);

/** 
 * Fonction poussee_realiser: 
 *************************
 * 
 * Realise une poussee sur un plateau en supposant que celle-ci 
 * est realisable. 
 * 
 * Necessite: 
 * - Un pointeur non NULL vers un plateau integre modifiable. 
 *-Deux coordonnees entieres (x,y) designant une piece non 
 *  vide integre du plateau.
 * - Un type d'animal a deplacer. 
 * - Une orientation de poussee designant une direction integre. 
 * - Un pointeur non NULL vers une condition de victoire modifiable. 
 * 
 * Garantie: 
 * - Un plateau integre mis a jour en ayant realise la poussee. 
 * 
 *
 */
  plateau_siam poussee_realiser(plateau_siam* plateau, int x, int y,type_piece type ,orientation_deplacement orientation,condition_victoire_partie* condition);
