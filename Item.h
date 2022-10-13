#include <string>
#ifndef ITEM_H
#define ITEM_H

class Item {
protected:
	static int currentId;
	int amount;
	double weight;
	std::string name;

public:
	const int ID;
	void setName(std::string name);
	std::string getName() { return name; };
	Item() : ID(currentId++), amount(-1), weight(-1.0), name("Undefined") {};
	Item(int _amnt, double _weight, std::string _name) : ID(currentId++), amount(_amnt), weight(_weight), name(_name) {};
};

#endif