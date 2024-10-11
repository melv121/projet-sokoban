#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

    void creer_plateau(JeuSokoban *jeu) {
    srand(time(NULL));
    for (int y = 0; y < HAUTEUR; y++) {
        for (int x = 0; x < LARGEUR; x++) {
            if (x == 0 || x == LARGEUR - 1 || y == 0 || y == HAUTEUR - 1) {
                jeu->plateau[y][x] = MUR;
            } else {
                jeu->plateau[y][x] = VIDE;
            }
        }
    }

   
    do {
        jeu->caisse_x = rand() % (LARGEUR - 2) + 1;
        jeu->caisse_y = rand() % (HAUTEUR - 2) + 1;
    } while (jeu->plateau[jeu->caisse_y][jeu->caisse_x] != VIDE);
    jeu->plateau[jeu->caisse_y][jeu->caisse_x] = CAISSE;

  
    do {
        jeu->joueur_x = rand() % (LARGEUR - 2) + 1;
        jeu->joueur_y = rand() % (HAUTEUR - 2) + 1;
    } while (jeu->plateau[jeu->joueur_y][jeu->joueur_x] != VIDE);
    jeu->plateau[jeu->joueur_y][jeu->joueur_x] = JOUEUR;

   
    do {
        jeu->cible_x = rand() % (LARGEUR - 2) + 1;
        jeu->cible_y = rand() % (HAUTEUR - 2) + 1;
    } while (jeu->plateau[jeu->cible_y][jeu->cible_x] != VIDE || 
             (jeu->cible_x == jeu->caisse_x && jeu->cible_y == jeu->caisse_y) || 
             (jeu->cible_x == jeu->joueur_x && jeu->cible_y == jeu->joueur_y));
    jeu->plateau[jeu->cible_y][jeu->cible_x] = CIBLE;
}


void afficher_plateau(JeuSokoban *jeu) {
    for (int y = 0; y < HAUTEUR; y++) {
        for (int x = 0; x < LARGEUR; x++) {
            printf("%c ", jeu->plateau[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}


int verifier_gagne(JeuSokoban *jeu) {
    return (jeu->caisse_x == jeu->cible_x && jeu->caisse_y == jeu->cible_y);
}


int est_caisse_bloquee(JeuSokoban *jeu) {
   
    if (jeu->plateau[jeu->caisse_y - 1][jeu->caisse_x] == MUR )
        
        { return 1; }
    
    else if (jeu->plateau[jeu->caisse_y + 1][jeu->caisse_x] == MUR) {
        
        return 1; 
    }
    
    
    else if (jeu->plateau[jeu->caisse_y][jeu->caisse_x - 1] == MUR) {
    
        return 1; }

    else if (jeu->plateau[jeu->caisse_y][jeu->caisse_x + 1] == MUR) {
        
        return 1; 
    }

    return 0; //
}

    void deplacer_joueur(JeuSokoban *jeu, char direction) {
    int nouvelle_x = jeu->joueur_x;
    int nouvelle_y = jeu->joueur_y;

    if (direction == 'z') nouvelle_y--; 
    else if (direction == 's') nouvelle_y++; 
    
    else if (direction == 'q') nouvelle_x--; 
    
    else if (direction == 'd') nouvelle_x++; 

    
    if (jeu->plateau[nouvelle_y][nouvelle_x] != MUR) {
        
        if (nouvelle_x == jeu->caisse_x && nouvelle_y == jeu->caisse_y) {
            int nouvelle_caisse_x = jeu->caisse_x;
            
            int nouvelle_caisse_y = jeu->caisse_y;

            if (direction == 'z') nouvelle_caisse_y--; 
            else if (direction == 's') nouvelle_caisse_y++; 
           
            else if (direction == 'q') nouvelle_caisse_x--;
            
            else if (direction == 'd') nouvelle_caisse_x++; 

            if (jeu->plateau[nouvelle_caisse_y][nouvelle_caisse_x] != MUR && 
               
                jeu->plateau[nouvelle_caisse_y][nouvelle_caisse_x] != CAISSE) {
                jeu->plateau[jeu->caisse_y][jeu->caisse_x] = VIDE; 
                jeu->caisse_x = nouvelle_caisse_x; 
                jeu->caisse_y = nouvelle_caisse_y;
                jeu->plateau[jeu->caisse_y][jeu->caisse_x] = CAISSE; 
            }
        }

       
        jeu->plateau[jeu->joueur_y][jeu->joueur_x] = VIDE;
        jeu->joueur_x = nouvelle_x;
        jeu->joueur_y = nouvelle_y;
        jeu->plateau[jeu->joueur_y][jeu->joueur_x] = JOUEUR;

        

        if (est_caisse_bloquee(jeu)) {
            afficher_plateau(jeu);
            printf("La caisse est bloquée entre deux murs ! Vous avez perdu.\n");
            exit(0);  
        }
    }
}
