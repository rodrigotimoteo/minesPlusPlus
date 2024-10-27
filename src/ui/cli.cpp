#include <iostream>

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

void gameLoop() {
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

            while(width <= 0) {
                std::cout << "Please enter a width: ";
                std::cin >> width;
                
                if(checkCinFailed()) {
                    std::cout << "Invalid width try again!\n";
                }
            }

            while(height <= 0) {
                std::cout << "Please enter a height: ";
                std::cin >> width;
                
                if(checkCinFailed()) {
                    std::cout << "Invalid height try again!\n";
                }
            }

            while(width <= 0) {
                std::cout << "Please enter the number of bombs: ";
                std::cin >> width;
                
                if(checkCinFailed()) {
                    std::cout << "Invalid value try again!\n";
                }
            }

            break;
        case 2: 
            std::exit(0);
            break;


        Level level(width, height, bombs);

        int gameRunning = 1;

        while(gameRunning) {

        }
    }

}
