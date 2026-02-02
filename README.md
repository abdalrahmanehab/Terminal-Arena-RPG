# 🎮 Terminal Arena

A robust C++ turn-based combat simulation built to demonstrate mastery of **Object-Oriented Programming (OOP)** and **Dynamic Memory Management**.

## 📖 About the Project
Developed as part of my 2nd-year engineering curriculum at **Mansoura University**, this project explores the practical application of C++ fundamentals in a game-logic environment. It features a polymorphic battle engine where different character classes interact through a unified interface.

## 🚀 Key Features
* **Polymorphic Combat Loop:** A single engine that manages diverse creature types seamlessly using base-class pointers.
* **Customizable Super-Hero:** Specialized initialization for the first hero, allowing user-defined health and damage stats.
* **Randomized Special Abilities:** Integrated probability logic for unique moves like "Heal" or "Scream" during combat.
* **Robust Input Sanitization:** Custom validation logic to handle invalid data types and ensure a crash-free user experience.

## 📂 Project Structure
```text
.
├── Creature.h      # Abstract Base Class defining the interface
├── Hero.h          # Specialized class with healing capabilities
├── Monster.h       # Specialized class with unique combat roars
├── main.cpp        # Entry point containing the battle engine & UI
├── README.md       # Project documentation
└── .gitignore      # Git rules to exclude build artifacts
