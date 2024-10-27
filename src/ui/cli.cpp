#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "cli.hpp"
#include "../core/game.hpp"

bool checkCinFailed() {
    if(std::cin.fail()) {
        std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    }
    
    return false;
}

void menuLoop() {
    std::cout << "Welcome to minesPlusPlus\n";

    int menuOption = 0;

    while(menuOption == 0) {
        std::cout << "Please select an option\n";
        std::cout << "1 - Play\n";
        std::cout << "2 - Quit\n";
        std::cout << "Option: ";

        std::cin >> menuOption;

        if(checkCinFailed()) {
            std::cout << "Invalid option try again!\n";
        }
    }

    int width = 0, height = 0, bombs = 0;

    switch(menuOption) {
        case 1: 
            std::cout << "\n\nLets play!\n";

            while(width <= 5) {
                std::cout << "Please enter a width (minimum is 6): ";
                std::cin >> width;
                
                if(checkCinFailed()) {
                    std::cout << "Invalid width try again!\n";
                }
            }

            while(height <= 5) {
                std::cout << "Please enter a height (minimum is 6): ";
                std::cin >> height;
                
                if(checkCinFailed()) {
                    std::cout << "Invalid height try again!\n";
                }
            }

            while(bombs <= 0) {
                std::cout << "Please enter the number of bombs: ";
                std::cin >> bombs;
                
                if(checkCinFailed()) {
                    std::cout << "Invalid value try again!\n";
                }
            }

            break;

        case 2: 
            std::exit(0);
            break;
        }

    gameLoop(width, height, bombs);
}

bool checkInputs(std::vector<std::string> vector, int width, int height) {
    if(vector.size() != 3) {
        return false; 
    }
    if(!vector[0].empty() && (vector[0] != std::string("p") || vector[0] != std::string("f"))) {
        return false;
    }

    //Lacks int values checks

    return true;
}

void gameLoop(int width, int height, int bombs) {
    Level level(width, height, bombs);
    checkCinFailed();

    int gameRunning = 1;

    std::cout << "This is the game menu!\n";
    std::cout << "To play follow the following syntax\n";
    std::cout << "Play: \"p x y\" where x and y are coordinates\n";
    std::cout << "To flag: \"f x y\" where x and y are coordinates\n";

    std::string play;
    std::string playType;
    int x = 0, y = 0;

    while(gameRunning != 0) {
        std::cout << "Input: ";
        std::getline(std::cin, play);
        std::stringstream ss(play);
       
        std::vector<std::string> tempVector;
        std::string temp;

        while(ss >> temp) {
            tempVector.push_back(temp);
        }

        std::cout << tempVector.size();

        if(!checkInputs(tempVector, level.getWidth(), level.getHeight())) {
            std::cout << "Invalid command!\n";
            continue;
        }

        playType = tempVector[0];
        x = std::stoi(tempVector[1]);
        y = std::stoi(tempVector[2]);

        Coord2D coord;
        coord.x = x, coord.y = y;
        level.play(coord);
    }

}
