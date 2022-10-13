#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "Weapon.h"

class Character
{
private:
	std::string name;
	std::vector<Weapon> weapons;
	int health = 5;

public:
	Character();
	Character(std::string characterName, int newHealth = -1);
	std::string getName();
	void setName(std::string &characterName);
	void addWeapon();
	void printWeapons();
};

#endif
