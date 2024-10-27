#pragma once

#include <vector>

/**
 * Coordinate helper struct
 **/ 
struct Coord2D {
    unsigned int x;
    unsigned int y;

    /**
     * != Operator overload
     **/ 
    bool operator!=(Coord2D coord);
};

class Level {
private:
    std::vector<std::vector<char>> board;

    bool initialized = false;
    unsigned int bombs;

public:
    /**
     * Default constructor
     **/ 
    explicit Level(unsigned int width, unsigned int height, unsigned int bombs);

    /**
     * Initializes the board considering the first coordinate played by the player
     * Avoids the first click being a bomb making the game a bit stupid
     **/
    void initBoard(Coord2D coord);

    /**
     * Makes a play on the board if no play has been done yet (initialized = false)
     * initializes the board
     **/
    void play(Coord2D coord);

    /**
     * Gets the val of the given coordinate (true if bomb false otherwise)
     **/
    bool getCell(Coord2D coord);

    /**
     * Gets the Width of the Board
     **/ 
    unsigned int getWidth();

    /**
     * Gets the Height of the Board
     **/  
    unsigned int getHeight();
};
