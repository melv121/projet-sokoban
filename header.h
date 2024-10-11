#ifndef HEADER_H
#define HEADER_H

#define LARGEUR 10
#define HAUTEUR 10

#define MUR '#'
#define VIDE ' '
#define JOUEUR 'O'
#define CAISSE 'X'
#define CIBLE '.'

typedef struct {
    char plateau[HAUTEUR][LARGEUR];
    int joueur_x;
    int joueur_y;
    int caisse_x;
    int caisse_y;
    int cible_x;
    int cible_y;
} JeuSokoban;

void creer_plateau(JeuSokoban *jeu);
void afficher_plateau( JeuSokoban *jeu);
int verifier_gagne( JeuSokoban *jeu);
void deplacer_joueur(JeuSokoban *jeu, char direction);
int est_caisse_bloquee( JeuSokoban *jeu);

#endif // HEADER_H
