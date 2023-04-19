#include <iostream>
#include <string>

using namespace std;

// Base Character class 
class Character {
public:
    string name;
    int health;
    int level;
    
    // Virtual function for using abilities
    virtual void useAbility(int) = 0;
};

// Warrior class inheriting from Character
class Warrior: public Character {
public:
    void useAbility(int abilityID) {
        if (abilityID == 1) {  // Ability 1: Power Strike
            cout << name << " uses Power Strike!" << endl;
        }
    }
};

// Archer class inheriting from Character 
class Archer: public Character {
public:
    void useAbility(int abilityID) {
        if (abilityID == 1) {  // Ability 1: Fire Arrow
            cout << name << " uses Fire Arrow!" << endl;
        }
    } 
};

// Mage class inheriting from Character
class Mage: public Character {
public:
    void useAbility(int abilityID) {
        if (abilityID == 1) {  // Ability 1: Fireball
            cout << name << " casts Fireball!" << endl;
        }
    }
}; 

// Ability class 
class Ability {
public:
    string name;
    int damage;
    int manaCost;
    
    // Virtual function for executing ability
    virtual void execute() = 0; 
};

int main() {
    // Create warrior character
    Warrior warrior;
    warrior.name = "Warrior";
    warrior.health = 100;
    warrior.level = 1;
    
    // Select and use Power Strike ability
    warrior.useAbility(1);
    
    // Create archer character
    Archer archer;
    archer.name = "Archer";
    archer.health = 80;
    archer.level = 1;
    
    // Select and use Fire Arrow ability
    archer.useAbility(1);  
    
    // Create mage character
    Mage mage;
    mage.name = "Mage";
    mage.health = 50;
    mage.level = 1;
    
    // Select and use Fireball ability
    mage.useAbility(1);  
}