#include <iostream>
#include <string>
#include "Character.h"
#include "Weapon.h"
#include "GameManager.h"

int main()
{
    std::string name;
    std::string action;
    Character hero;
    GameManager GM('$');

    /* Game Start Message Begin */
    std::cout << "*******************************" << std::endl;
    std::cout << "* Simple Text RPG             *" << std::endl;
    std::cout << "* Type 'die' to end the game  *" << std::endl;
    std::cout << "*******************************" << std::endl;
    /* Game Start Message End */

    std::cout << "What is your name?\n> ";
    std::cin >> name;
    hero.setName(name);

    std::cout << "Very well, " << hero.getName() << ". Let's get started!" << std::endl;

    while (true)
    {
        GM.displayMap();

        break;
        if (action == "exit") break;
        if (action == "add_weapon") hero.addWeapon();
        if (action == "inventory") hero.printWeapons();
    }

    return 0;
}