#pragma once
#include <iostream>
#include <string>

class Creature {
protected:
    int health;
    int maxHealth;
    std::string name;
    int damage;

public:
    Creature() : health(100), maxHealth(100), name("Unknown"), damage(0) {}

    Creature(std::string n, int h, int d)
        : name(n), health(h), maxHealth(h), damage(d) {
    }

    virtual ~Creature() {}

    bool isAlife() { return health > 0; }

    void setName(std::string name) { this->name = name; }
    std::string getName() { return name; }

    void takeDamage(int dmg) {
        health -= dmg;
        if (health < 0) health = 0;
    }

    void setHealth(int h) { health = h; }
    int getHealth() { return health; }

    virtual void attack(Creature& target) = 0;

    //pure virtual function
    virtual void specialAbility() = 0;
};