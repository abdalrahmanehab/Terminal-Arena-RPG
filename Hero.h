#pragma once
#include "Creature.h"

class Hero : public Creature {
public:
    Hero(std::string n, int h, int d) : Creature(n, h, d) {}

    ~Hero() {}

    void heal() {
        health = maxHealth;
        std::cout << name << " restored their health to " << maxHealth << "!\n";
    }

    void attack(Creature& target) override {
        std::cout << name << " slashes his sword at " << target.getName() << "!\n";

        target.takeDamage(damage);

        if (target.getHealth() <= 0) {
            std::cout << "FATAL BLOW! " << target.getName() << " has been defeated!\n";
        }
        else {
            std::cout << "   " << target.getName() << " health is now: " << target.getHealth() << "\n";
        }
    }

    void specialAbility() override {
        heal();
    }
};