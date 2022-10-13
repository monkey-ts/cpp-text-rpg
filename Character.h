#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "Weapon.h"
#include "PlayerManager.h"

class Character
{
protected:
	std::string name;
	std::vector<Weapon> weapons;
	int health = 5;
	PlayerManager  *ply_manager = new PlayerManager();

public:
	Character();
	Character(std::string characterName, int newHealth = -1);
	~Character();
	std::string getName();
	void setName(std::string &characterName);
	void addWeapon();
	void printWeapons();
};

#endif
