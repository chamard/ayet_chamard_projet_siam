

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
 *
 * Implementation des fonction de entree_sortie.
 *
 */



#include "entree_sortie.h"


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_MAX 512


int entree_sortie_fichier_etre_accessible(const char* filename)
{
    assert(filename!=NULL);

    //tente d'ouvir le fichier en ecriture/ajout
    // si le pointeur n'est pas nulle
    //  alors le fichier est accessible
    // sinon le fichier n'est pas accessible
    FILE *fid=NULL;
    fid=fopen(filename,"a+");

    if(fid==NULL)
        return 0;

    fclose(fid);
    return 1;
}

int entree_sortie_fichier_exister(const char* filename)
{

    assert(filename!=NULL);

    //tente d'ouvir le fichier en lecture seule
    // si le pointeur n'est pas nulle
    //  alors le fichier est accessible
    // sinon le fichier n'est pas accessible

    FILE *fid=NULL;
    fid=fopen(filename,"r");

    if(fid==NULL)
        return 0;

    fclose(fid);
    return 1;
}


void entree_sortie_ecrire_jeu_fichier(const char* filename,const jeu_siam* jeu)
{
    assert(filename!=NULL);
    assert(jeu!=NULL);
    assert(jeu_etre_integre(jeu));
    assert(entree_sortie_fichier_etre_accessible(filename)==1);

    // Ouvre fichier
    FILE *fid=NULL;
    fid=fopen(filename,"w");
    assert(fid!=NULL);
    if(fid==NULL) //double protection en mode release
    {
        printf("Erreur ouverture fichier %s\n",filename);
        abort();
    }

    entree_sortie_ecrire_jeu_pointeur_fichier(fid,jeu);

    // Ferme fichier
    int c=fclose(fid);
    if(c!=0) //double protection
    {
        printf("Erreur fermeture fichier %s\n",filename);
        abort();
    }
}





void entree_sortie_lire_jeu_fichier(const char* filename,jeu_siam* jeu)
{
    
    const char* _for="Erreur ouverture fichier %s\n",*_jeu="Erreur lecture numero de ligne",*_while="Jeu invalide lecture fichier %s\n";
        
    int i,j,k;
    char * machaine=NULL;
    char * nom1=NULL, *nom2=NULL,*nom3=NULL,*nom4=NULL,*nom5=NULL;
    
    filename = "etat_courant" ; 
    FILE *fid= NULL ;
    fid= fopen ( filename , "w" ); 
    
        if (fid== NULL ) 
    {printf ( "Erreur ouverture du fichier %s\n" , filename ); exit (1);}
    
    fgets (machaine,50,fid);
    sscanf(machaine,"%s %d %s",nom1,&k,nom2);
    jeu->joueur=k;
    
    for(j=0;j<NBR_CASES;j++)
    {
        fgets (machaine,50,fid);
        sscanf(machaine,"[%d] %s | %s | %s | %s | %s |",&k,nom1,nom2,nom3,nom4,nom5 ); 
        
        for(i=0;i<NBR_CASES;i++)
        {
        jeu->plateau.piece[i][k]=piece_correspondre_nom_cours(nom1);
        jeu->plateau.piece[i][k]=piece_correspondre_nom_cours(nom2);
        jeu->plateau.piece[i][k]=piece_correspondre_nom_cours(nom3);
        jeu->plateau.piece[i][k]=piece_correspondre_nom_cours(nom4);
        jeu->plateau.piece[i][k]=piece_correspondre_nom_cours(nom5);
        }
        
    }
    
    int c= fclose (fid);
        if (c!= 0 ) 
    {printf ( "Erreur fermeture fichier %s\n" , filename ); exit (1);}
    
  }

void entree_sortie_ecrire_jeu_pointeur_fichier(FILE* identifiant,const jeu_siam* jeu)
{
    assert(identifiant!=NULL);
    assert(jeu!=NULL);


    const plateau_siam* plateau=&jeu->plateau;
    assert(plateau!=NULL);

    fprintf(identifiant,"joueur %d (%s)\n",jeu->joueur,type_nommer(jeu_obtenir_type_animal_courant(jeu)));

    entree_sortie_ecrire_plateau_pointeur_fichier(identifiant,plateau);

}

void entree_sortie_ecrire_plateau_pointeur_fichier(FILE* identifiant,const plateau_siam* plateau)
{
      
    assert(identifiant!=NULL);
    assert(plateau!=NULL);
    assert(plateau_etre_integre(plateau));
   
    
    int i,j;
    
    for(i=NBR_CASES-1;i>=0;i--)
    {
      fprintf(identifiant,"[%d]",i);
      for(j=0;j<NBR_CASES;j++)
      {
    if(plateau->piece[i][j].type==elephant || plateau->piece[i][j].type==rhinoceros)
    {
    fprintf(identifiant," %s",type_nommer_nom_cours(plateau->piece[i][j].type));
    fprintf(identifiant,"-%s",orientation_nommer_nom_cours(plateau->piece[i][j].orientation));
    fprintf(identifiant," |");
    }
    else
    {
    fprintf(identifiant," %s",type_nommer_nom_cours(plateau->piece[i][j].type));
    fprintf(identifiant," |");
    }
    
      }
      fprintf(identifiant,"\n");
      }
      fprintf(identifiant,"    ");
      for(j=0;j<NBR_CASES;j++)
      {
      fprintf(identifiant,"[%d]   ",j);
    }
      fprintf(identifiant,"\n");
    
      
    
}





