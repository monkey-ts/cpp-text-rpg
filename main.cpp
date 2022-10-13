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
    std::cout << "* Type 'exit' to end the game *" << std::endl;
    std::cout << "*******************************" << std::endl;
    /* Game Start Message End */

    std::cout << "What is your name?\n> ";
    std::getline(std::cin, name);
    hero.setName(name);

    std::cout << "Very well, " << hero.getName() << ". Let's get started!" << std::endl;

    while (true)
    {
        GM.displayMap();

        std::cout << "Type an action to do something:" << std::endl;
        std::cout << "Note: you can move with left/l, right/r, down/d, up/u" << std::endl;
        std::cin >> action;

        if (action == "exit") break;
        if (action == "add_weapon") hero.addWeapon();
        if (action == "inventory") hero.printWeapons();
        if (action == "down" || action == "d") GM.movePlayerY(1);
        if (action == "up" || action == "u") GM.movePlayerY(-1);
        if (action == "left" || action == "l") GM.movePlayerX(-1);
        if (action == "right" || action == "r") GM.movePlayerX(1);

        std::cout << std::endl;
    }

    return 0;
}