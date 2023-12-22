#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Entity {
public:
    std::string race = "Entite Mysterieuse";
    void parle() {
        std::cout << "Salut ! Petit etre.\n";
    }


    std::string getRace() {
        return race;
    }
private:   
    void salutation() {
        std::cout << "Yo.\n";
    }
protected:
    void adieu() {
        std::cout << "Au revoir.\n";
    }
};

class Player : public Entity {
public:
    std::string race = "Humain";
    int health = 100;
    int attack = 20;

    void parle() {
        std::cout << "Suis-je... un homme...\n";
    }

    std::string getRace() {
        return race;
    }

    void setHealth(int dammage) {
        health = health - dammage;
    }

    int getAttack() {
        return attack;
    }

    void reset_health() {
        health = 100;
    }
};

class Npc : public Entity {
public:
    std::string race = "Humain";
    void parle() {
        std::cout << "Les hommes ont besoin d'un hero. Un hero tel que vous pour nous proteger des demons.\n";
    }

    std::string getRace() {
        return race;
    }
};

class Monster : public Entity {
public:
    std::string race = "monstre";
    int health = 10;
    int attack = 5;

    void parle() {
        std::cout << "Grr ! HUMAIN !!!\n";
    }

    std::string getRace() {
        return race;
    }

    virtual void dit() {
        std::cout << "setamot sed ceva nob sert tnos sniamuh sel" << std::endl;
    }

    void setHealth(int dammage) {
        health = health - dammage;
    }

    int getAttack() {
        return attack;
    }
};

class Goblin : public Monster {
public:
    std::string race = "goblin";
    int health = 30;
    int attack = 10;

    void parle() {
        std::cout << "Grananahana. Viande de toi etre succulente... surement\n";
    }

    std::string getRace() {
        return race;
    }

    void setHealth(int dammage) {
        health = health - dammage;
    }

    int getAttack() {
        return attack;
    }
};

class Demon : public Monster {
public:
    std::string race = "demon";
    int health = 100;
    int attack = 15;

    void parle() {
        std::cout << "En tant que etre d'une race superieur. J'aneantirais tous les humains.\n";
    }

    std::string getRace() {
        return race;
    }

    void setHealth(int dammage) {
        health = health - dammage;
    }

    int getAttack() {
        return attack;
    }
};

int main() {
    Entity entity;
    Player player;
    Monster monster;
    Npc npc;
    Goblin goblin;
    Demon demon;


    player.parle();
    std::cout << "Race du specimen : " + player.getRace() + "\n";
    monster.parle();
    std::cout << "Race du specimen : " + monster.getRace() + "\n";
    npc.parle();
    std::cout << "Race du specimen : " + npc.getRace() + "\n";
    goblin.parle();
    std::cout << "Race du specimen : " + goblin.getRace() + "\n";
    demon.parle();
    std::cout << "Race du specimen : " + demon.getRace() + "\n";
    entity.parle();
    std::cout << "Race du specimen : " + entity.getRace() + "\n";

    return 0;
}
