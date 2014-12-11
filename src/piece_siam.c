#include "piece_siam.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int piece_etre_integre(const piece_siam* piece)
{
    assert(piece!=NULL);
     if ((piece->type==elephant || piece->type==rhinoceros)&&(piece->orientation==haut || piece->orientation==bas || piece->orientation==gauche || piece->orientation==droite))
   	return 1;
     if ((piece->type==rocher || piece->type==case_vide) && (piece->orientation==aucune_orientation))
       return 1;
    
    return 0;
}

void piece_initialiser(piece_siam* piece)
{
    assert(piece!=NULL);

    piece_definir(piece,case_vide,aucune_orientation);

    assert(piece_etre_integre(piece));
}

int piece_etre_animal(const piece_siam* piece)
{
  assert(piece!=NULL||piece_etre_integre(piece)==0);
  if(piece->type==elephant || piece->type==rhinoceros)
    return 1;
  else
    return 0;
}


int piece_etre_rocher(const piece_siam* piece)
{
  assert(piece!=NULL||piece_etre_integre(piece)==0);
   if(piece->type==rocher)
    return 1;
  else
    return 0;
}


int piece_etre_case_vide(const piece_siam* piece)
{
  assert(piece!=NULL||piece_etre_integre(piece)==0);
   if(piece->type==case_vide)
    return 1;
  else
    return 0;
}




void piece_definir(piece_siam* piece,type_piece type,orientation_deplacement orientation)
{
    assert(piece!=NULL);
    piece->type=type;
    piece->orientation=orientation;
    assert(piece_etre_integre(piece));
}


void piece_definir_rocher(piece_siam* piece)
{
    assert(piece!=NULL);
    piece_definir(piece,rocher,aucune_orientation);
    assert(piece_etre_integre(piece));
}

void piece_definir_case_vide(piece_siam* piece)
{
    assert(piece!=NULL);
    piece_definir(piece,case_vide,aucune_orientation);
    assert(piece_etre_integre(piece));
}





orientation_deplacement piece_recuperer_orientation_animal(const piece_siam* piece)
{
    assert(piece!=NULL);
    assert(piece_etre_integre(piece));
    assert(piece_etre_animal(piece));

    return piece->orientation;
}


void piece_afficher(const piece_siam* piece)
{
    assert(piece!=NULL);

    printf("%s,%s",type_nommer(piece->type),orientation_nommer(piece->orientation));
}

void piece_afficher_nom_cours(const piece_siam* piece)
{
    assert(piece!=NULL);

    printf("%s",type_nommer_nom_cours(piece->type));
    if(piece_etre_animal(piece))
        printf("-%s",orientation_nommer_nom_cours(piece->orientation));
}


piece_siam piece_correspondre_nom_cours(const char* nom_cours)
{
    assert(nom_cours!=NULL);
    assert(strlen(nom_cours)==3);
    piece_siam piece;
    piece_initialiser(&piece);


    if(strncmp(nom_cours,"***",3)==0)
    {
        piece_definir_case_vide(&piece);
    }
    else if(strncmp(nom_cours,"RRR",3)==0)
    {
        piece_definir_rocher(&piece);
    }
    else if((nom_cours[0]=='e' || nom_cours[0]=='r') && nom_cours[1]=='-')
    {
        const type_piece type=type_correspondre_caractere_animal(nom_cours[0]);
        const orientation_deplacement orientation=orientation_correspondre_caractere(nom_cours[2]);

        piece_definir(&piece,type,orientation);
    }
    else
    {
        printf("Erreur fonction %s\n",__FUNCTION__);
        abort();
    }

    return piece;

}

void test_piece_etre_integre()
{
  puts("test_piece_etre_integre");
  piece_siam* piece;
  
  piece_siam premiere_piece;
  piece=&premiere_piece;
  piece->orientation=aucune_orientation;
  piece->type=elephant;
  if (piece_etre_integre(piece)==1)
    puts("KO");
  if (piece_etre_integre(piece)==0)
    puts("OK");

  piece_siam deuxieme_piece;
  piece=&deuxieme_piece;
  piece->orientation=gauche;
  piece->type=rhinoceros;
  if (piece_etre_integre(piece)==1)
    puts("OK");
  if (piece_etre_integre(piece)==0)
    puts("KO");
}

void test_piece_etre_un_animal() 
{
  
  puts("test_piece_etre_animal");
  piece_siam* piece;
  
  piece_siam premiere_piece;
  piece=&premiere_piece;
  piece->type=elephant;
  if (piece_etre_animal(piece)==1)
    puts("OK");
  if (piece_etre_animal(piece)==0)
    puts("KO");
  
   piece_siam deuxieme_piece;
  piece=&deuxieme_piece;
  piece->type=case_vide;
  if (piece_etre_animal(piece)==1)
    puts("KO");
  if (piece_etre_animal(piece)==0)
    puts("OK");
  
  
}