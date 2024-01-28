#include <iostream>
#include <cstdlib> // random

class Entity {
public:
    std::string nom;
    Entity() {
        nom = "Computer";
    }
    int choix() {
        return rand() % 3; // Génère un nombre aléatoire entre 0 et 2
    }
};

class Player : public Entity {
public:
    int choix() {
        int num = 0;
        std::cout << "pierre (0) feuille (1) ou ciseau (2) : ";
        std::cin >> num;
        return num;
    }
};


void match(Entity& joueur1, Entity& joueur2) {
    int scoreJoueur1 = 0;
    int scoreJoueur2 = 0;

    while (scoreJoueur1 < 3 && scoreJoueur2 < 3) {
        int choixJoueur1 = joueur1.choix();
        int choixJoueur2 = joueur2.choix();

        std::cout << "Joueur 1 a choisi : " << choixJoueur1 << std::endl;
        std::cout << "Joueur 2 a choisi : " << choixJoueur2 << std::endl;

        if ((choixJoueur1 == 0 && choixJoueur2 == 2) ||
            (choixJoueur1 == 1 && choixJoueur2 == 0) ||
            (choixJoueur1 == 2 && choixJoueur2 == 1)) {
            std::cout << "Joueur 1 gagne le point !" << std::endl;
            scoreJoueur1++;
        } else if ((choixJoueur2 == 0 && choixJoueur1 == 2) ||
                   (choixJoueur2 == 1 && choixJoueur1 == 0) ||
                   (choixJoueur2 == 2 && choixJoueur1 == 1)) {
            std::cout << "Joueur 2 gagne le point !" << std::endl;
            scoreJoueur2++;
        } else if (choixJoueur1 == choixJoueur2){
            std::cout << "Égalité !" << std::endl;
        } else {
            std::cout << "Error" << std::endl;
        }
    }

    if (scoreJoueur1 == 3) {
        std::cout << joueur1.nom << " gagne la partie !" << std::endl;
    } else {
        std::cout << joueur2.nom << " gagne la partie !" << std::endl;
    }
}

int main() {
    std::string nom1, nom2, choixj2;
    std::cout << "entrer ton nom ";
    std::cin >> nom1;
    Player player1;
    player1.nom = nom1;
    std::cout << "voulez-vous jouer contre un ami ? (y) ";
    std::cin >> choixj2;
    if (choixj2 == "y" || choixj2 == "Y") {
        std::cout << "entrer ton nom ";
        std::cin >> nom2;
        Player player2;
        player2.nom = nom2;
        match(player1, player2);
    } else {
        std::cout << "Joueur 2 est l'ordinateur." << std::endl;
        Entity player2;
        match(player1, player2);
    }
    // Ajout de la rejouabilité plus tard
    return 0;
}
