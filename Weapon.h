#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : public Item {
	int damage;

public:
	Weapon() : damage(0) {};
	Weapon(int _damage, int _amount, double _weight, std::string _name) : Item(_amount, _weight, _name), damage(_damage) {};
	int getDamage() { return damage; }
	void setDamage(int _damage);
};

#endif