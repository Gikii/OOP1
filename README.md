# Virtual World Simulator

A turn-based, two-dimensional grid simulator of a virtual ecosystem populated by various interacting life forms (animals and plants). This project was developed as an Object-Oriented Programming (OOP) assignment to deeply practice concepts such as inheritance, polymorphism, encapsulation, and abstraction in C++.

<img width="1020" height="998" alt="Zrzut ekranu 2026-02-24 221156" src="https://github.com/user-attachments/assets/1c9d4838-8ee3-4e91-aa75-2083bb974467" />

## Core Architecture and OOP Principles

The simulator is strictly designed around Object-Oriented paradigms:
* **Abstraction:** Utilizes a core abstract `Organism` class, branching into abstract `Animal` and `Plant` classes, defining interfaces for actions and collisions.
* **Polymorphism:** Resolution of interactions (eating, fighting, multiplying, reflecting attacks) is handled dynamically at runtime using virtual methods (e.g., `action()`, `collision()`, `draw()`) without relying on hardcoded type-checking.
* **Encapsulation:** Class members and properties (strength, initiative, position) are heavily protected, exposed only when necessary to the `World` manager class.
* **World Manager:** A central `World` class manages the 2D grid, orchestrating turns, rendering the state, and maintaining the collection of organisms sorted by initiative and age.

## Implemented Features

1. **Turn-Based Ecosystem:** Organisms take actions sequentially based on their `initiative` stat. Ties are resolved by the organism's age.
2. **Entity Interactions (Collisions):**
   * **Combat:** When two different animal species collide, the one with higher strength survives. If strengths are equal, the attacker wins.
   * **Reproduction:** When two animals of the same species collide, they spawn a new animal of that species on an adjacent empty tile.
3. **Plant Propagation:** Plants have a specific probability to spread to adjacent empty tiles during their turn.
4. **Save/Load System:** The complete state of the world can be saved to a text file and restored later.
5. **Console Visualization:** The world is rendered in the terminal using ASCII characters, with an event log at the bottom detailing fights, eating, and special events.

## Organisms and Specific Behaviors

### Animals
* **Wolf (Strength 9, Initiative 5):** Apex predator, standard movement.
* **Sheep (Strength 4, Initiative 4):** Standard herbivore.
* **Fox (Strength 3, Initiative 7):** Good sense of smell; will never move to a tile occupied by an organism stronger than itself.
* **Turtle (Strength 2, Initiative 1):** Remains stationary 75% of the time. Reflects attacks from animals with a strength of strictly less than 5.
* **Antelope (Strength 4, Initiative 4):** Moves 2 tiles per turn. Has a 50% chance to escape combat by jumping to an adjacent empty tile.

### Plants (Zero Initiative)
* **Grass:** Standard plant.
* **Dandelion:** Attempts to spread 3 times per turn.
* **Guarana:** Permanently increases the strength of the animal that eats it by 3.
* **Deadly Nightshade (Belladonna):** Kills any animal that consumes it.
* **Sosnowsky's Hogweed:** Kills all animals in its immediate vicinity at the start of its turn. Kills any animal that attempts to eat it.

### The Human (Player)
* **Movement:** Controlled manually using keyboard arrow keys.
* **Special Ability:** Can be activated via a specific keybind. Once activated, it lasts for 5 turns, followed by a mandatory 5-turn cooldown period.

## Setup and Compilation

This project was originally developed using Microsoft Visual Studio, but it can be easily compiled with any standard C++ compiler (e.g., GCC, Clang) across different operating systems.

### Using GCC (Linux / macOS / MinGW)
1. Clone the repository and navigate to the project directory.
2. Compile all source files simultaneously using the wildcard command:
   `g++ *.cpp -o simulator -Wall`
3. Run the application:
   `./simulator`
