#ifndef MAP_H
#define MAP_H

#include <tuple>
#include <vector>
#include "Entity.h"

class Map {
protected:
	static const unsigned int height = 5;
	static const unsigned int length = 5;
	bool visible = true;
	char border = '#';
	std::vector<Entity*> entities;

public:
	~Map();
	void draw();
	std::tuple<unsigned int, unsigned int> drawEntities(int& currRow, int& currCol, int& entsDrawn);
	inline void setVisible(bool toggle) {
		visible = toggle;
	};
	void addEntity(Entity* entity);
	void listEntities();
	static inline unsigned int getHeight() { return height;  };
	static inline unsigned int getLength() { return length;  };
};

#endif
