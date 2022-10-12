#include <iostream>
#include <string>
#include "Character.h"

int main()
{
    bool gameRunning = true;
    std::string name;
    std::string action;
    Character hero;

    std::cout << "*******************************" << std::endl;
    std::cout << "* Simple Text RPG             *" << std::endl;
    std::cout << "* Type 'die' to end the game  *" << std::endl;
    std::cout << "*******************************" << std::endl;

    std::cout << "What is your name?\n> ";
    std::cin >> name;
    hero.setName(name);

    while (gameRunning)
    {
        std::cout << "Okay, " << hero.getName() << ". What would you like to do?" << std::endl << std::endl;
        std::cin >> action;

        if (action == "die") gameRunning = false;
        if (action == "add_weapon") hero.addWeapon();
        if (action == "inventory") hero.printWeapons();
    }

    return 0;
}