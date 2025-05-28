# Dungeons and Dragons OOP Project

This project is an object-oriented simulation of a classic Dungeons and Dragons-inspired universe, implemented in C++. The architecture is designed to reflect core principles of OOP, providing a base for extensible and modular gameplay logic.

## Core OOP Concepts

### Abstractization

In the characters module, `CharacterBase` serves as an abstract class. It defines the shared structure and behavior of all adventurers without dictating specific implementations. Derived classes like `Fighter` and `Mage` provide their own versions of essential actions. This abstraction allows the engine to treat all characters uniformly while preserving their individual essence.

---

### Polymorphism

Combat, interaction, and decision-making are handled generically through base class pointers or references. When a character attacks or defends, the actual behavior depends on its derived class implementation. This polymorphic structure allows `BattleManager` to interact with characters through a common interface, while the underlying logic is dynamically determined.

---

### Virtualisation

Methods in `CharacterBase`, such as `takeTurn()` or `performAction()`, are declared as `virtual`. This enables derived classes to override these behaviors, offering distinct responses depending on class type. Virtual functions allow the system to delegate responsibility to the most appropriate specialization without hardcoding class-specific logic.

---

### Incapsulation

Critical attributes like health, inventory, and ability scores are protected or private within their respective classes. Controlled access is provided through public getters and setters. This encapsulation enforces data integrity and prevents unintended side effects, supporting maintainability and flexibility in gameplay logic.

---

### Interfaces

`ISpellCaster` is a pure virtual interface that defines expected behavior for magic-using entities. Any class that implements this interface must define spellcasting methods, allowing polymorphic treatment of casters across the system. This separation supports multiple inheritances and isolates responsibilities.

---

### Singleton Class

`GameState` is implemented as a Singleton, ensuring that there is exactly one instance representing the world’s current status. All systems that need global context refer to this centralized object. Its construction is hidden and managed internally to prevent duplication and maintain a consistent world state across the simulation.

---

## Compilation & Execution

To build and run the simulation:

```bash
g++ -std=c++17 main.cpp game/*.cpp characters/*.cpp items/*.cpp -o dnd_sim
./dnd_sim

---

Let me know if you'd like a Makefile or example implementations to complement this README.

