
#ifndef ENTITY_H
#define ENTITY_H

class Entity {
protected:
	unsigned int x, y;
public:
	Entity();
	std::tuple<unsigned int, unsigned int> getPos();
	std::tuple<unsigned int, unsigned int> getRandPos();
};

#endif