#include "GameManager.h"
#include <iostream>
#include <random>
#include <tuple>

void GameManager::displayMap()
{
    if (!shouldShowMap) return;
    auto enemyPos = getEnemyPos();

    for (unsigned int i = 0; i < mapHeight; i++) {

        for (unsigned int j = 0; j < mapLength; j++) {
            // Draw the player
            if (i == py && j == px) {
                if (i == std::get<1>(enemyPos) && j == std::get<0>(enemyPos)) {
                    startCombat();
                    std::cout << "?";
                }
                else { 
                    std::cout << "X"; 
                }
                continue;
            }

            // Draw the enemy
            if (i == std::get<1>(enemyPos) && j == std::get<0>(enemyPos)) {
                std::cout << "*";
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

bool GameManager::playerInBounds(unsigned int xy, char pos) {
    unsigned int bounds = {};

    if (pos == 'x') bounds = mapLength - 1;
    if (pos == 'y') bounds = mapHeight - 1;

    if (xy < bounds && xy > 0) return true;

    std::cout << "[ERROR]: Player tried to move out of bounds." << std::endl;
    return false;
}

bool GameManager::playerInBounds(unsigned int &x, unsigned int &y) {
    if (y < mapHeight - 1 && x < mapLength - 1 && y > 0 && x > 0) return true;

    std::cout << "[ERROR]: Player tried to move out of bounds." << std::endl;
    return false;
}

std::tuple<unsigned int, unsigned int> GameManager::getEnemyPos() {
    int min_x = 1;
    int min_y = 1;
    int max_x = mapLength - 2;
    int max_y = mapHeight - 2;

    std::random_device randDev;
    std::mt19937 rng(randDev());
    std::uniform_int_distribution<std::mt19937::result_type> distX(min_x, max_x);
    std::uniform_int_distribution<std::mt19937::result_type> distY(min_y, max_y);

    return std::make_tuple(distX(rng), distY(rng));
}

void GameManager::startCombat() {
    shouldShowMap = false;
    std::cout << "Oh shit we fightin' out here bois" << std::endl;
}

