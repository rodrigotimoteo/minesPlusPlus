#include "game.hpp"
#include <cassert>
#include <cstdlib>
#include <vector>

#include "../core/game.hpp"

bool Coord2D::operator!=(Coord2D coord) {
    return this->x != coord.x && this->y != coord.y;
}

Level::Level(unsigned int width, unsigned int height, unsigned bombs) : bombs(bombs) { 
    assert((width * height) / 2 > bombs);
    assert(width > 5 && height > 5);

    board.reserve(height);

    for(int i {0}; i < width; i++) {
        std::vector<char> newLine (width, '0');

        board.push_back(newLine);
    }
}

void Level::initBoard(Coord2D coord) {
    for(int i {0}; i < bombs; i++) {
        Coord2D newBomb;
        newBomb.x = rand() % board.size();
        newBomb.y = rand() % board[0].size();

        if(coord != newBomb) {
            board[newBomb.x][newBomb.y] = '1';
        } else {
            i--;
            continue;
        }
    }
}

void Level::play(Coord2D coord) {
    if(!initialized) {
        initBoard(coord);
    } else {

    }
}

bool Level::getCell(Coord2D coord) {
    return board[coord.x][coord.y];
}

unsigned int Level::getWidth() {
    return board.size(); 
}

unsigned int Level::getHeight() {
    return board[0].size();
}
