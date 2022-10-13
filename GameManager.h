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
	bool playerInBounds(int x, int y);

	void setPlayerX(int x) {
		if (playerInBounds(x, 'x')) px = x;
	}

	void setPlayerY(int y) {
		if (playerInBounds(y, 'y')) py = y;
	}

	void movePlayer(int x, int y) {
		if (playerInBounds(x, y)) {
			px = x;
			py = y;
		};
	}
};

#endif
