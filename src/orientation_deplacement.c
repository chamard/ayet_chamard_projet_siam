#include "orientation_deplacement.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int orientation_etre_integre(orientation_deplacement orientation)
{
    // L'enumeration designe une orientation integre si elle est compris
    //  entre 0 et 5.
    // Une enumeration etant un type non signee, il est forcement positif.
    // Il suffit donc que type soit < 5 pour designer un type valide.

    if(orientation<5)
        return 1;
    return 0;
}

int orientation_etre_integre_deplacement(orientation_deplacement direction_deplacement)
{
    // L'enumeration designe une orientation integre si elle est compris
    //  entre 0 et 4.
    // Une enumeration etant un type non signee, il est forcement positif.
    // Il suffit donc que type soit < 4 pour designer un type valide.

    if(direction_deplacement<4)
        return 1;
    return 0;
}
const char* orientation_nommer(orientation_deplacement orientation)
{
    // "Look up table" (LUT) convertissant une orientation vers
    //    la chaine de caractere correspondante.

    switch(orientation)
    {
    case haut:
        return "haut";
    case bas:
        return "bas";
    case gauche:
        return "gauche";
    case droite:
        return "droite";
    case aucune_orientation:
        return "aucune";
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}



const char* orientation_nommer_nom_cours(orientation_deplacement orientation)
{
    // "Look up table" (LUT) convertissant une orientation vers
    //    la chaine de caractere courte correspondante.

    switch(orientation)
    {
    case haut:
        return "^";
    case bas:
        return "v";
    case gauche:
        return "<";
    case droite:
        return ">";
    case aucune_orientation:
        return "????";
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}

orientation_deplacement orientation_inverser(orientation_deplacement orientation)
{
    assert(orientation_etre_integre_deplacement(orientation));

    // "Look up table" (LUT) convertissant une orientation vers
    //    son oppose
    // haut   <-> bas
    // droite <-> gauche


    switch(orientation)
    {
    case haut:
        return bas;
    case bas:
        return haut;
    case gauche:
        return droite;
    case droite:
        return gauche;
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}


int orientation_caractere_etre_integre(char orientation)
{
  
    if(orientation=='v')
      return 1;
    if(orientation=='^')
      return 1;
    if(orientation=='<')
      return 1;
    if(orientation=='>')
      return 1;

    return 0;

}

orientation_deplacement orientation_correspondre_caractere(char orientation)
{ 
  assert(orientation_caractere_etre_integre(orientation)==1);
  
  switch(orientation)
    {
    case 'v':
        return bas;
    case '^':
        return haut;
    case '>':
        return droite;
    case '<':
        return gauche;
    default:
	return 0;
    }
}
void test_orientation_etre_integre_deplacement(){
	puts("test_orientation_etre_integre_deplacement");
	if(orientation_etre_integre_deplacement(haut)==1)
		puts("haut OK");
	if(orientation_etre_integre_deplacement(bas)==1)
		puts("bas OK");
	if(orientation_etre_integre_deplacement(gauche)==1)
		puts("gauche OK");
	if(orientation_etre_integre_deplacement(droite)==1)
		puts("droite OK");
	if(orientation_etre_integre_deplacement(aucune_orientation)!=1)
		puts("aucune_orientation KO");
}

void test_orientation_caractere_etre_integre(){
	puts("test_orientation_caractere_etre_integre");
	if(orientation_caractere_etre_integre('v')==1)
		puts("v OK");
	if(orientation_caractere_etre_integre('>')==1)
		puts("> OK");
	if(orientation_caractere_etre_integre('<')==1)
		puts("< OK");
	if(orientation_caractere_etre_integre('^')==1)
		puts("^ OK");
	if(orientation_caractere_etre_integre('a')==1)
		puts("a OK !!! ");
	if(orientation_caractere_etre_integre('1')==1)
		puts("1 OK !!! ");
	if(orientation_caractere_etre_integre('?')==1)
		puts("? OK !!! ");
	if(orientation_caractere_etre_integre('p')==1)
		puts("p OK !!! ");
	if(orientation_caractere_etre_integre('6')==1)
		puts("6 OK !!! ");
}

void test_orientation_correspondre_caractere(){
	puts("test_orientation_correspondre_caractere");
	if(orientation_correspondre_caractere('v')==bas)
		puts("bas 'v' OK");
	if(orientation_correspondre_caractere('^')==haut)
		puts("haut '^' OK");
	if(orientation_correspondre_caractere('>')==droite)
		puts("droite '>' OK");
	if(orientation_correspondre_caractere('<')==gauche)
		puts("gauche '<' OK");

}