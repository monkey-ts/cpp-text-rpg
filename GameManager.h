#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class GameManager {
	int mapHeight = 10;
	int mapLength = 20;
	int px = 1;
	int py = 1;
	char mapChar;

public: 
	GameManager() : mapChar('#') {};

	explicit GameManager(char _mapChar) : mapChar(_mapChar) {};

	GameManager(int h, int len, char _mapChar) : mapHeight(h), mapLength(len), mapChar(_mapChar) {};

	void displayMap();

	inline void setMapHeight(int h) { mapHeight = h; };

	inline void setMapLength(int len) { mapLength = len; };

	inline int getMapHeight() {
		return mapHeight;
	};

	inline int getMapLength() {
		return mapLength;
	}

	inline int getMapArea() {
		return mapLength * mapHeight;
	}

	bool playerInBounds(int xy, char pos);
	bool playerInBounds(int &x, int &y);

	void movePlayerX(int x) {
		if (playerInBounds(px+x, 'x')) px += x;
	}

	void movePlayerY(int y) {
		if (playerInBounds(py+y, 'y')) py += y;
	}

	void movePlayer(int x, int y) {
		int _x = px + x;
		int _y = py + y;
		if (playerInBounds(_x, _y)) {
			px = _x;
			py = _y;
		};
	}
};

#endif
