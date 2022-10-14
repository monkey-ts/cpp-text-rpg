#include <iostream>
#include <tuple>
#include <vector>
#include "Entity.h"
#include "Map.h"

std::tuple<unsigned int, unsigned int> Map::drawEntities(int &currRow, int &currCol, int &entsDrawn) {
   
    if (entities.empty()) return std::make_tuple(-1, -1);
    if (entsDrawn == entities.size()) return std::make_tuple(-1, -1);

    for (auto ent : entities) {
        auto pos = ent->getPos();
        if (currRow == std::get<0>(pos) && currCol == std::get<1>(pos)) {
            ++entsDrawn;
            return pos;
        }
    }

    return std::make_tuple(-1, -1);
}

void Map::draw() {
    if (!visible) return;
    int entitiesDrawn = 0; 
    
    for (auto i = 0; i < height; i++) {
        for (auto j = 0; j < length; j++) {
            auto entityPos = drawEntities(i, j, entitiesDrawn);
            if (std::get<0>(entityPos) && std::get<1>(entityPos) != -1) {
                std::cout << '?';
                continue;
            };

            if (i == 0 || i == height - 1) {
                std::cout << border;
                continue;
            };
            if (j == 0 || j == length - 1) std::cout << border;
            else std::cout << " ";
        }

        std::cout << std::endl;
    }
}

void Map::listEntities() {
    for (auto& ent : entities) {
        std::cout << std::get<0>(ent->getPos()) << std::endl;
    }
}

void Map::addEntity(Entity* ent) {
    entities.push_back(ent);
    std::cout << "Successfully added entity." << std::endl;
}

Map::~Map() {
    for (auto p : entities) {
        delete p;
    }

    entities.clear();
}