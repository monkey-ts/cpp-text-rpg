#include "Character.h"
#include <iostream>

Character::Character()
{
    name = "Unnamed";
}

Character::Character(std::string characterName, int newHealth)
{
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
        std::cout << "\t" << weapon << std::endl;
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

    std::cout << std::endl;
    weapons.push_back(weaponName);
}