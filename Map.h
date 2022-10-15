#ifndef MAP_H
#define MAP_H

#include <tuple>
#include <vector>
#include "Entity.h"

class Map {
protected:
	static const unsigned int height = 5;
	static const unsigned int length = 10;
	bool visible = true;
	char border = '#';
	std::vector<std::vector<char>> map;

public:
	Map();
	void draw();
	inline void setVisible(bool toggle) {
		visible = toggle;
	};
	static inline unsigned int getHeight() { return height;  };
	static inline unsigned int getLength() { return length;  };
};

#endif
