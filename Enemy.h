#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include <string>

class Enemy : public Character {
	std::string battleCry = "";
public:
	Enemy() : Character() {};
	void sayBattleCry();
};

#endif