#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include <iostream>
#include <tuple>
#include "GameManager.h" 

class PlayerManager {
private:
	unsigned int x, y;
	GameManager* GM;

public:
	void setPos(unsigned int x, unsigned int y);
	inline std::tuple<unsigned int, unsigned int> getPos();
	inline unsigned int getX();
	inline unsigned int getY();
};

#endif