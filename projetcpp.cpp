#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class Entite {
public:
    Entite(const std::string& nom, int pointsDeVie, int pointsAttaque)
        : nom(nom), pointsDeVie(pointsDeVie), pointsAttaque(pointsAttaque) {}

    virtual ~Entite() {}

    virtual void afficher() const {
        std::cout << "Nom: " << nom << "\nPoints de vie: " << pointsDeVie << "\nPoints d'attaque: " << pointsAttaque << "\n";
    }

    virtual bool estEnVie() const {
        return pointsDeVie > 0;
    }

    virtual void attaquer(Entite& cible) {
        std::cout << nom << " attaque " << cible.getNom() << "!\n";
        cible.recevoirDegats(pointsAttaque);
    }

    virtual void recevoirDegats(int degats) {
        pointsDeVie -= degats;
        if (pointsDeVie < 0) {
            pointsDeVie = 0;
        }
        std::cout << nom << " subit " << degats << " points de dégâts. Points de vie restants: " << pointsDeVie << "\n";
    }

    const std::string& getNom() const {
        return nom;
    }

private:
    std::string nom;
    int pointsDeVie;
    int pointsAttaque;
};

class Personnage : public Entite {
public:
    using Entite::Entite;

};

class Monstre : public Entite {
public:
    using Entite::Entite;
};

void combat(Personnage joueur, Monstre monstre){
    std::cout << "=== Informations initiales ===\n";
    joueur.afficher();
    monstre.afficher();
    while (joueur.estEnVie() && monstre.estEnVie()) {
        int choix;
        std::cout << "1. Attaquer\n2. Fuir\n";
        std::cin >> choix;
        switch (choix) {
            case 1:
                std::cout << "Vous attaquez le monstre!\n";
                joueur.attaquer(monstre);
                if (!monstre.estEnVie()) {
                    std::cout << "Vous avez vaincu le monstre!\n";
                    break;
                }

                monstre.attaquer(joueur);
                if (!joueur.estEnVie()) {
                    std::cout << "Vous avez été vaincu par le monstre...\n";
                    break;
                }
            
                break;
            case 2:
                std::cout << "Vous fuyez le combat!\n";
                return;
            default:
                std::cout << "Choix invalide!\n";
        }
    }
}
int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Personnage joueur("Héros", 30, 10);

    Monstre gobelin("Gobelin", 20, 5);

    Monstre loup("Loup", 15, 5);

    Monstre slime("Slime", 15, 1);

    combat(joueur, slime);
    combat(joueur, loup);
    combat(joueur, gobelin);

    return 0;
}