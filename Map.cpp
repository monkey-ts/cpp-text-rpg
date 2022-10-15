#include <iostream>
#include <tuple>
#include <vector>
#include "Entity.h"
#include "Map.h"

Map::Map() {
    map.resize(this->height);

    for (int map_row = 0; map_row < this->height; ++map_row) {
        for (int map_column = 0; map_column < this->length; ++map_column) {
            if (
                map_row == 0 || map_row == this->height - 1 || 
                map_column == 0 || map_column == this->length - 1) 
            {
                map.at(map_row).push_back(border);
            }
            else {
                map.at(map_row).push_back(' ');
            }
            
        }
    }
}

void Map::draw() {
    if (!visible) return;
    int entitiesDrawn = 0; 
    
    for (auto i = 0; i < height; i++) {
        for (auto j = 0; j < length; j++) {
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