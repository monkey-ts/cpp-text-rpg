#include <tuple>
#include <string>
#include <iostream>
#include "PlayerManager.h"

inline std::tuple<unsigned int, unsigned int> PlayerManager::getPos() {
	return std::make_tuple(x, y);
}

void PlayerManager::setPos(unsigned int x, unsigned int y) {
	
}

inline unsigned int PlayerManager::getX() {
	return x;
}

inline unsigned int PlayerManager::getY() {
	return y;
}