#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Monster.h"
#include "Hero.h"

using namespace std;

// Function that checks if the input is valid
int getValidInput(string prompt) {
    int n;
    cout << prompt;
    while (!(cin >> n) || n <= 0) {
        cout << "Invalid! Please enter a positive number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return n;
}


// function to center the writtine text on the screen
void centerText(string text, int width = 80) {
    int padding = (width - text.length()) / 2;
    for (int i = 0; i < padding; i++) cout << " ";
    cout << text << endl;
}



int main() {
    centerText("================================================================\n");
    centerText("Welcome to Terminal Arena\n");
    centerText("================================================================\n");


    vector<Creature*> heros;
    vector<Creature*> monsters;

    // Using the function for the first time here
    int count = getValidInput("How many heroes do you want? ");
    cout << "\n";

    string name;

    for (int i = 0; i < count; i++) {
        if (i == 0) {
            cout << "Your first hero is a super hero and you can set their health and damage!\n";
        }

        cout << "Enter the name of hero number " << i + 1 << " : ";
        cin >> name;

        if (i == 0) {
            // Using the function for Super Hero stats
            int superheroHealth = getValidInput("Enter super hero health: ");
            int superheroDamage = getValidInput("Enter super hero damage: ");

            Creature* c = new Hero(name, superheroHealth, superheroDamage);
            heros.push_back(c);
            cout << "\n";
            continue;
        }

        Creature* c = new Hero(name, 100, 20);
        heros.push_back(c);
        cout << "\n";
    }

    // Using the function for monster count
    int monsterCount = getValidInput("How many Monsters do you want? ");
    cout << "\n";

    for (int i = 0; i < monsterCount; i++) {
        cout << "Enter the name of Monster number " << i + 1 << " : ";
        cin >> name;
        Creature* c = new Monster(name, 100, 5);
        monsters.push_back(c);
        cout << "\n";
    }

    srand(static_cast<unsigned int>(time(0)));

    while (!heros.empty() && !monsters.empty()) {

        // --- Heroes Turn ---
        for (size_t i = 0; i < heros.size(); i++) {
            if (monsters.empty()) break;

            // 30% chance to use Special Ability, otherwise Attack
            if (rand() % 10 < 3) {
                heros[i]->specialAbility();
            }
            else {
                int targetIndex = rand() % (int)monsters.size();
                heros[i]->attack(*monsters[targetIndex]);

                if (!monsters[targetIndex]->isAlife()) {
                    delete monsters[targetIndex];
                    monsters.erase(monsters.begin() + targetIndex);
                }
            }
        }

        // --- Monsters Turn ---
        for (size_t i = 0; i < monsters.size(); i++) {
            if (heros.empty()) break;

            // 20% chance for Monster to Scream/Special, otherwise Attack
            if (rand() % 10 < 2) {
                monsters[i]->specialAbility();
            }
            else {
                int targetIndex = rand() % (int)heros.size();
                monsters[i]->attack(*heros[targetIndex]);

                if (!heros[targetIndex]->isAlife()) {
                    delete heros[targetIndex];
                    heros.erase(heros.begin() + targetIndex);
                }
            }
        }
    }


    cout << "\n\n";

    centerText("================================================================\n");
    if (heros.empty()) {
        centerText("GAME OVER... The Monsters have won!\n");
    }
    else {
        centerText("VICTORY! The Heroes have saved the world!\n");
    }
    centerText("================================================================\n");


    // delete the rest alive creatures from the heap to avoid memory leak

    for (auto h : heros) delete h;
    for (auto m : monsters) delete m;
    heros.clear();
    monsters.clear();


    return 0;
}