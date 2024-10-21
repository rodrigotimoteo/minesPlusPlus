#include "game.hpp"
#include <cassert>
#include <cstdlib>
#include <vector>

bool Coord2D::operator!=(Coord2D coord) {
    return this->x != coord.x && this->y != coord.y;
}

Level::Level(unsigned int width, unsigned int height, unsigned bombs) : bombs(bombs) { 
    assert(width * height < bombs / 2);
    assert(width > 5 && height > 5);

    board.reserve(10);

    for(int i {0}; i < width; i++) {
        std::vector<bool> newLine (width, false);

        board.push_back(newLine);
    }
}

void Level::initBoard(Coord2D coord) {
    for(int i {0}; i < bombs; i++) {
        Coord2D newBomb;
        newBomb.x = rand() % board.size();
        newBomb.y = rand() % board[0].size();

        if(coord != newBomb) {
            board[newBomb.x][newBomb.y] = true;
        } else {
            i--;
            continue;
        }
    }
}

bool Level::getCell(Coord2D coord) {
    return board[coord.x][coord.y];
}
