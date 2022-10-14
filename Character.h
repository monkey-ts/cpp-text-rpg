#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <string>
#include "PlayerManager.h"
#include "Weapon.h"
#include "Entity.h"

class Character : public Entity
{
protected:
	std::string name;
	std::vector<Weapon> weapons;
	int health = 5;
	PlayerManager * ply_manager;

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
