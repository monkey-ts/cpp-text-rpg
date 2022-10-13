#include "GameManager.h"
#include <iostream>

void GameManager::displayMap()
{
    for (int i = 0; i < mapHeight; i++) {

        for (int j = 0; j < mapLength; j++) {
            if (i == py && j == px) {
                std::cout << "X";
                continue;
            }
            
            if (!(i == 0 || i == mapHeight - 1)) {
                if (j == 0 || j == mapLength - 1) std::cout << mapChar;
                else std::cout << " ";

                continue;
            }

            std::cout << mapChar;
        }

        std::cout << std::endl;

    }

    std::cout << std::endl;
}

bool GameManager::playerInBounds(int xy, char pos) {
    int bounds = {};

    if (pos == 'x') bounds = mapLength - 1;
    if (pos == 'y') bounds = mapHeight - 1;

    if (xy < bounds && xy > 0) return true;

    std::cout << "[ERROR]: Player tried to move out of bounds." << std::endl;
    return false;
}

bool GameManager::playerInBounds(int &x, int &y) {
    if (y < mapHeight - 1 && x < mapLength - 1 && y > 0 && x > 0) return true;

    std::cout << "[ERROR]: Player tried to move out of bounds." << std::endl;
    return false;
}