#include <iostream>
#include <string>
#include <vector>
#include "PlayerManager.h"
#include "Entity.h"
#include "Weapon.h"
#include "Character.h"

Character::Character()
{
    name = "Unnamed";
    ply_manager = new PlayerManager();
}

Character::Character(std::string characterName, int newHealth)
{

    ply_manager = new PlayerManager();
    if (newHealth > -1)
        health = newHealth;
    if (name == "")
        return;

    name = characterName;
}

void Character::setName(std::string &characterName)
{
    if (characterName == "") {
        std::cout << "Character name cannot be empty." << std::endl;
        return;
    }

    characterName[0] = toupper(characterName[0]);
    name = characterName;
}

std::string Character::getName() 
{
    return name;
}

void Character::printWeapons() {
    std::cout << "You have the following items:" << std::endl;
    for (auto& weapon : weapons) {
        std::cout << "\t" << weapon.getName() << std::endl;
    }
}

void Character::addWeapon() 
{
    std::string weaponName;

    std::cout << "What would you like to add to your inventory? ";
    std::cin.ignore();
    std::getline(std::cin, weaponName);

    if (weaponName == "") {
        std::cout << "[ERROR]: Weapon name cannot be empty." << std::endl;
        return;
    }

    if (weapons.size() >= 5) {
        std::cout << weaponName << " cannot be added to inventory. Inventory full!" << std::endl;
        return;
    }

    Weapon newWeapon(0, 1, 0.0, weaponName);

    std::cout << std::endl;
    weapons.push_back(newWeapon);
}

// Destructor
Character::~Character() {
    delete ply_manager;
}