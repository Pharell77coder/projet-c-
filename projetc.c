#include <stdio.h>
#include <stdlib.h>

struct Joueur {
    char nom[50];
    int points_de_vie;
    int points_attaque;
};

void initialiserJoueur(struct Joueur* joueur, const char* nom, int points_de_vie, int points_attaque) {
    snprintf(joueur->nom, sizeof(joueur->nom), "%s", nom);
    joueur->points_de_vie = points_de_vie;
    joueur->points_attaque = points_attaque;
}

void afficherJoueur(const struct Joueur* joueur) {
    printf("Nom: %s\nPoints de vie: %d\nPoints d'attaque: %d\n", joueur->nom, joueur->points_de_vie, joueur->points_attaque);
}

void rencontreMonstre(struct Joueur* joueur) {
    printf("Un monstre approche!\n");

    int points_de_vie_monstre = 20;
    int points_attaque_monstre = 5;

    while (joueur->points_de_vie > 0 && points_de_vie_monstre > 0) {
        printf("1. Attaquer\n2. Fuir\n");

        int choix;
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Vous attaquez le monstre!\n");
                points_de_vie_monstre -= joueur->points_attaque;
                break;
            case 2:
                printf("Vous fuyez le combat!\n");
                return;
            default:
                printf("Choix invalide!\n");
        }

        joueur->points_de_vie -= points_attaque_monstre;
        printf("Le monstre vous attaque!\n");

        printf("Vos points de vie: %d\nPoints de vie du monstre: %d\n", joueur->points_de_vie, points_de_vie_monstre);
    }

    if (joueur->points_de_vie > 0) {
        printf("Vous avez vaincu le monstre!\n");
    } else {
        printf("Vous avez été vaincu par le monstre...\n");
    }
}

int main() {
    struct Joueur joueur;
    initialiserJoueur(&joueur, "Héros", 30, 10);

    afficherJoueur(&joueur);

    rencontreMonstre(&joueur);

    return 0;
}