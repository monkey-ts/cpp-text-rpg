#include "Item.h"

int Item::currentId = 0;

void Item::setName(std::string _name) {
	if (_name == "") return;

	name = _name;
}