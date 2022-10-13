#include "GameManager.h"
#include <iostream>

void GameManager::displayMap() {
    for (int i = 0; i < mapHeight; i++) {
        if (!(i == 0 || i == mapHeight-1)) {
            for (int j = 0; j < mapLength; j++) {
                if (j == 0 || j == mapLength-1) std::cout << mapChar;
                else std::cout << " ";
            }

            std::cout << std::endl;
            continue;
        }

        for (int j = 0; j < mapLength; j++) {
            std::cout << mapChar;
        }

        std::cout << std::endl;
    }
}