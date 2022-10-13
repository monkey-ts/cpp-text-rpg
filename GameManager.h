#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <tuple>

class GameManager {
	unsigned int mapHeight = 10;
	unsigned int mapLength = 20;
	unsigned int px = 1;
	unsigned int py = 1;
	char mapChar;
	bool shouldShowMap = true;

public: 
	GameManager() : mapChar('#') {};

	explicit GameManager(char _mapChar) : mapChar(_mapChar) {};

	GameManager(int h, int len, char _mapChar) : mapHeight(h), mapLength(len), mapChar(_mapChar) {};

	void displayMap();

	inline void setMapHeight(unsigned int h) { mapHeight = h; };

	inline void setMapLength(unsigned int len) { mapLength = len; };

	inline unsigned int getMapHeight() {
		return mapHeight;
	};

	inline unsigned int getMapLength() {
		return mapLength;
	}

	inline unsigned int getMapArea() {
		return mapLength * mapHeight;
	}

	bool playerInBounds(unsigned int xy, char pos);
	bool playerInBounds(unsigned int &x, unsigned int &y);

	void movePlayerX(unsigned int x) {
		if (playerInBounds(px+x, 'x')) px += x;
	}

	void movePlayerY(unsigned int y) {
		if (playerInBounds(py+y, 'y')) py += y;
	}

	void movePlayer(unsigned int x, unsigned int y) {
		auto _x = px + x;
		auto _y = py + y;
		if (playerInBounds(_x, _y)) {
			px = _x;
			py = _y;
		};
	}

	inline unsigned int getPlayerX() {
		return px;
	}

	inline unsigned int getPlayerY() {
		return py;
	}

	inline std::tuple<unsigned int, unsigned int> getPlayerPos() {
		return std::make_tuple(px, py);
	}

	std::tuple<unsigned int, unsigned int> getEnemyPos();

	void startCombat();
};

#endif
