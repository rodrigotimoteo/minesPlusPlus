#include "game.hpp"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <vector>

bool Coord2D::operator!=(Coord2D coord) {
    return this->x != coord.x && this->y != coord.y;
}

Level::Level(unsigned int width, unsigned int height, unsigned bombs) : bombs(bombs) { 
    assert((width * height) / 2 > bombs);
    assert(width > 5 && height > 5);

    board.reserve(height);
    playerBoard.reserve(height);

    for(int i {0}; i < width; i++) {
        std::vector<char> newLine (width, ' ');

        board.push_back(newLine);
    }

    for(int i {0}; i < width; i++) {
        std::vector<char> newLine (width, ' ');

        playerBoard.push_back(newLine);
    }
}

void Level::randomizeBoard(std::vector<std::vector<char>>& board, Coord2D startCoord) { 
    for(int i {0}; i < bombs; i++) {
        board[i % board.size()][i] = 'b';
    }

    std::srand(time(0));

    for(int i {0}; i < getHeight(); i++) {
        for(int j {0}; j < getWidth(); j++) {
            int randX = (std::rand() * getWidth()) % getWidth();
            int randY = (std::rand() * getHeight()) % getHeight();

            char temp = board[i][j];
            board[i][j] = board[randY][randX];
            board[randY][randX] = temp;
        }
    }

    if(board[startCoord.y][startCoord.x] == 'b') {
        for(int i = getHeight() - 1; i >= 0; i--) {
            for(int j = getWidth() - 1; j >= 0; j--) {
                if(board[i][j] != 'b') {
                    char temp = board[startCoord.y][startCoord.x];
                    board[startCoord.y][startCoord.x] = board[i][j];
                    board[i][j] = temp;
                }
            }
        }
    }
}

void Level::initBoard(Coord2D coord) {
    randomizeBoard(board, coord);

    printBoard();
}

void Level::play(Coord2D coord, std::string type) {
    if(!initialized) {
        initBoard(coord);
    } else {
        if(type == std::string("p")) {

        } else {

        }
    }
}

char Level::getCell(Coord2D coord) {
    return board[coord.x][coord.y];
}

void Level::printBoard() {
    for(int i {0}; i < getHeight(); i++) { 
        for(int j {0}; j < getWidth(); j++) {
            std::cout << board[i][j] << " (" << j << ", " << i << ")";
        }
        std::cout << std::endl;
    }
}

unsigned int Level::getWidth() {
    return board.size(); 
}

unsigned int Level::getHeight() {
    return board[0].size();
}
