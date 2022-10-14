#include <tuple>
#include <random>
#include "Map.h"
#include "Entity.h"

Entity::Entity() : x(1), y(1)
{
}

std::tuple<unsigned int, unsigned int> Entity::getPos() {
	return std::make_tuple(x, y);
}

std::tuple<unsigned int, unsigned int> Entity::getRandPos() {
	std::random_device device;
	std::mt19937 rng(device());
	std::uniform_int_distribution<std::mt19937::result_type> distX(1, Map::getLength() - 2);
	std::uniform_int_distribution<std::mt19937::result_type> distY(1, Map::getHeight() - 2);

	return std::make_tuple(distX(rng), distY(rng));
}