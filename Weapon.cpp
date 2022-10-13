#include "Weapon.h"
#include <string>
#include <iostream>

void Weapon::setDamage(int _damage) {
	if (_damage <= 0) return;
	damage = _damage;
}