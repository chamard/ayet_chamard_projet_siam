#include "type_piece.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int type_etre_integre(type_piece type)
{
    // L'enumeration designe un type integre si elle est comprise
    //  entre 0 et 4.
    // Une enumeration etant un type non signee, il est forcement positif.
    // Il suffit donc que type soit < 4 pour designer un type valide.
    if(type<4)
        return 1;
    return 0;
}


int type_etre_animal(type_piece type)
{
    if(type<2)
        return 1;
    return 0;
}


const char* type_nommer(type_piece type)
{
    // "Look up table" (LUT) convertissant un type de piece vers
    //    la chaine de caractere correspondante.

    switch(type)
    {
    case elephant:
        return "elephant";
    case rhinoceros:
        return "rhinoceros";
    case rocher:
        return "rocher";
    case case_vide:
        return "vide";
    default:
        printf("Erreur, type piece %d non reconnue",type);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}


const char* type_nommer_nom_cours(type_piece type)
{
    // "Look up table" (LUT) convertissant un type de piece vers
    //    la chaine de caractere courte correspondante.

    switch(type)
    {
    case elephant:
        return "e";
    case rhinoceros:
        return "r";
    case rocher:
        return "RRR";
    case case_vide:
        return "***";
    default:
        printf("Erreur, type piece %d non reconnue",type);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}

int type_caractere_animal_etre_integre(char type)
{
    // Verifie que le caractere correspond a elephant (e) ou rhinoceros (r).
    if(type=='e' || type=='r')
        return 1;
    return 0;
}

type_piece type_correspondre_caractere_animal(char type)
{
  assert(type_caractere_animal_etre_integre(type));
  
  type_piece type2=elephant;
  
  if(type=='e')
    type2=elephant;
  else
    type2=rhinoceros;
  return type2;
}

void test_type_etre_integre(){
  puts("test type_etre_integre");
  
  if(type_etre_animal(elephant)==1)
    puts("elephant=animal OK");
  if(type_etre_animal(rhinoceros)==1)
    puts("rhinoceros=animal OK");
  if(type_etre_animal(rocher)!=1)
    puts("rocher=animal KO");
  if(type_etre_animal(case_vide)!=1)
    puts("case vide=animal KO");
  
  int k=0;
  for(k=4;k<20;++k)
    if(type_etre_animal(k)!=0)
      printf("valeur %d KO\n",k); 
  
}
