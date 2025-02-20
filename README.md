# TOWER_DEFENSE



## **🔹 1. Overview**
This project implements a **Tower Defense game** with **Observer Pattern integration**.  
It includes:
- **Character Observer** → Updates when the character's health or attack power changes.
- **Map Observer** → Displays map updates when towers are placed.
- **ItemContainer Observer** → Tracks inventory changes when adding/removing items.

## **🔹 2. Compilation Instructions**
To compile the project, run:

g++ -std=c++17 -Iinclude -o game src/*.cpp -lsfml-system
./game

