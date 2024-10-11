#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
    JeuSokoban jeu;
    creer_plateau(&jeu);
    afficher_plateau(&jeu);

    while (1) {
        char mouvement;
        printf("Entrez votre mouvement (z/q/s/d) : ");
        scanf(" %c", &mouvement);

        deplacer_joueur(&jeu, mouvement);
        afficher_plateau(&jeu);

        if (verifier_gagne(&jeu)) {
            printf("Félicitations, vous avez gagné !\n");
            break;
        }
    }

    return 0;
}
