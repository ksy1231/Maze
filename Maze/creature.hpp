//
//  creature.hpp
//  Maze
//
//  Created by Soo Yun Kim on 4/1/20.
//  Copyright © 2020 Soo Yun Kim. All rights reserved.
//

#ifndef creature_hpp
#define creature_hpp

#include "maze.hpp"

#include <iostream>

class Creature {
    // prints current location of creature, for example C(7, 3)
    friend ostream &operator<<(ostream &out, const Creature &creature);
    
public:
    // constructor
    Creature(int row, int column);
    // destructor
    ~Creature();
    
    // returns a string in the form of NNEEN
    // (where N means North, E means East, etc)
    // that will let the creature get to the exit
    // if creature cannot get to the exit, returns "X"
    string Solve(Maze &maze);
    
    // If possible, moves the creature to the space directly north of the current
    // location. Recursively tries to move to north, west, east, and south.
    // Moves back to where it came from if failed to move.
    // Adds "N" to path and returns true if success, returns false otherwise
    bool goNorth(Maze &maze);
    // If possible, moves the creature to the space directly west of the current
    // location. Recursively tries to move to north, west, east, and south.
    // Moves back to where it came from if failed to move.
    // Adds "W" to path and returns true if success, returns false otherwise
    bool goWest(Maze &maze);
    // If possible, moves the creature to the space directly east of the current
    // location. Recursively tries to move to north, west, east, and south.
    // Moves back to where it came from if failed to move.
    // Adds "E" to path and returns true if success, returns false otherwise
    bool goEast(Maze &maze);
    // If possible, moves the creature to the space directly south of the current
    // location. Recursively tries to move to north, west, east, and south.
    // Moves back to where it came from if failed to move.
    // Adds "S" to path and returns true if success, returns false otherwise
    bool goSouth(Maze &maze);
    
    // reverse path in order to get the correct path
    void reversePath();
    
private:
    // current located row and column of the creature
    int row, column;
    // path to the exit
    string path;
    // help recursion
    bool success;
};

#endif /* creature_hpp */
