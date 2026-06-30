#include <iostream>
#include <string>

using namespace std;

// Abstraction: Abstract base class Player
class Player {
protected: // Encapsulation: Protected variables accessible by derived classes but not externally
    string playerName;
    int health;
    int energy;

public:
    Player(string name, int hp, int en) : playerName(name), health(hp), energy(en) {}

    // Pure virtual function making this an abstract class (Abstraction & Polymorphism)
    virtual void playRole() = 0; 

    // Encapsulation: Public getters and setters
    string getName() const { return playerName; }
    int getHealth() const { return health; }
    int getEnergy() const { return energy; }

    void setHealth(int hp) { health = hp; }
    void setEnergy(int en) { energy = en; }

    void takeDamage(int amount) {
        health -= amount;
        if (health < 0) health = 0;
        cout << playerName << " took " << amount << " damage! Health is now " << health << "." << endl;
    }

    void displayStats() const {
        cout << "Player: " << playerName << " | HP: " << health << " | Energy: " << energy << endl;
    }
};

// Inheritance: Sniper inherits from Player
class Sniper : public Player {
private:
    int damageOutput;

public:
    Sniper(string name) : Player(name, 100, 50), damageOutput(40) {}

    // Polymorphism: Overriding the pure virtual function
    void playRole() override {
        if (energy >= 15) {
            cout << playerName << " takes a long-range shot for " << damageOutput << " damage!" << endl;
            energy -= 15;
        } else {
            cout << playerName << " does not have enough energy to shoot!" << endl;
        }
    }
};

// Inheritance: Support inherits from Player
class Support : public Player {
private:
    int healAmount;

public:
    Support(string name) : Player(name, 120, 100), healAmount(30) {}

    // Polymorphism: Overriding the pure virtual function
    void playRole() override {
        cout << playerName << " provides defensive cover for the team!" << endl;
    }

    // Function to heal a teammate
    void healTeammate(Player* teammate) {
        cout << playerName << " is attempting to heal " << teammate->getName() << "..." << endl;
        if (energy >= 20) {
            int newHealth = teammate->getHealth() + healAmount;
            teammate->setHealth(newHealth);
            
            // BUG FIXED HERE: 
            // Support player should LOSE 20 energy.
            energy -= 20;
            
            cout << teammate->getName() << " has been healed for " << healAmount << " HP." << endl;
            cout << playerName << "'s energy is now " << energy << "." << endl;
        } else {
            cout << playerName << " does not have enough energy to heal!" << endl;
        }
    }
};

int main() {
    cout << "=== E-Sports Tournament Match Starts ===" << endl;

    // Creating Objects
    Sniper mySniper("Shadow");
    Support mySupport("Mercy");

    mySniper.displayStats();
    mySupport.displayStats();

    cout << "\n--- Action Phase ---" << endl;
    mySniper.playRole(); 
    mySniper.takeDamage(50);
    mySniper.displayStats();

    cout << "\n--- Healing Phase ---" << endl;
    // Mercy heals Shadow
    // Bug demonstration: Mercy's energy should decrease from 100 to 80, but will increase to 120.
    mySupport.healTeammate(&mySniper);

    cout << "\n--- Final Stats ---" << endl;
    mySniper.displayStats();
    mySupport.displayStats();

    return 0;
}
