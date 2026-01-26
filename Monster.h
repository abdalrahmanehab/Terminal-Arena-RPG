#pragma once
#include "Creature.h"

class Monster : public Creature {
public:
    Monster(std::string n, int h, int d) : Creature(n, h, d) {}

    ~Monster() {}

    std::string scream() {
        return "Roaarrr.. \n";
    }

    void attack(Creature& target) override {
        std::cout << name << " bites " << target.getName() << "!\n";

        target.takeDamage(damage);

        if (target.getHealth() <= 0) {
            std::cout << "CRUNCH! " << target.getName() << " has been slain!\n";
        }
        else {
            std::cout << "   " << target.getName() << " health is now: " << target.getHealth() << "\n";
        }
    }

    void specialAbility() override {
        std::cout << name << " screams: " << scream();
    }
};