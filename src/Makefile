CFLAGS=-g -Wall -Wextra

#all designe la cible par default
all: main

#compilation des sources et edition de liens

main: main.o api_siam.o condition_victoire_partie.o coordonnees_plateau.o coup_jeu.o entree_sortie.o jeu_siam.o joueur.o mode_interactif.o orientation_deplacement.o parseur_mode_interactif.o piece_siam.o plateau_modification.o plateau_siam.o type_piece.o pousse.o
	gcc main.o api_siam.o condition_victoire_partie.o coordonnees_plateau.o coup_jeu.o entree_sortie.o jeu_siam.o joueur.o mode_interactif.o orientation_deplacement.o parseur_mode_interactif.o piece_siam.o plateau_modification.o plateau_siam.o type_piece.o pousse.o -o ../bin/jeu_siam
api_siam.o: api_siam.c api_siam.h
condition_victoire_partie.o: condition_victoire_partie.c condition_victoire_partie.h
coordonnees_plateau.o: coordonnees_plateau.c coordonnees_plateau.h
coup_jeu.o: coup_jeu.c coup_jeu.h
entree_sortie.o: entree_sortie.c entree_sortie.h
jeu_siam.o: jeu_siam.c jeu_siam.h 
joueur.o: joueur.c joueur.h
main.o: main.c
mode_interactif.o: mode_interactif.c mode_interactif.h
orientation_deplacement.o: orientation_deplacement.c orientation_deplacement.h
parseur_mode_interactif.o: parseur_mode_interactif.c parseur_mode_interactif.h
piece_siam.o: piece_siam.c piece_siam.h
plateau_modification.o: plateau_modification.c plateau_modification.h 
plateau_siam.o: plateau_siam.c plateau_siam.h 
pousse.o: pousse.h pousse.c 
type_piece.o: type_piece.c type_piece.h

#clean permet de nettoyer le repertoire courant
clean:
	rm -f *.o *~ 