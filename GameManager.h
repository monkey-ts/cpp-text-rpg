#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class GameManager {
	int mapHeight;
	int mapLength;
	char mapChar;
public: 
	GameManager() : mapHeight(5), mapLength(10), mapChar('#') {};
	explicit GameManager(char _mapChar) : mapChar(_mapChar), mapHeight(5), mapLength(10) {};
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
};

#endif
