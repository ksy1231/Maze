//
//  creature.cpp
//  Maze
//
//  Created by Soo Yun Kim on 4/1/20.
//  Copyright © 2020 Soo Yun Kim. All rights reserved.
//

#include "creature.hpp"

// prints current location of creature, for example C(7, 3)
ostream &operator<<(ostream &out, const Creature &creature) {
    out << "C(" << creature.row << ", " << creature.column << ")";
    return out;
}

// constructor
Creature::Creature(int row, int column) : row{row}, column{column} {}

// destructor
Creature::~Creature() {}

// returns a string in the form of NNEEN
// (where N means North, E means East, etc)
// that will let the creature get to the exit
// if creature cannot get to the exit, returns "X"
string Creature::Solve(Maze &maze) {
    if (row == maze.row_exit && column == maze.column_exit) {
        path += "Exit";
    } else {
        success = goNorth(maze);
        if (!success) {
            success = goWest(maze);
            if (!success) {
                success = goEast(maze);
                if (!success) {
                    success = goSouth(maze);
                    if (!success) {
                        path = "X";
                    } else {
                        path += "S";
                    }
                } else {
                    path += "E";
                }
            } else {
                path += "W";
            }
        } else {
            path += "N";
        }
    }
    reversePath();
    return path;
}

// If possible, moves the creature to the space directly north of the current
// location. Recursively tries to move to north, west, east, and south.
// Moves back to where it came from if failed to move.
// Adds "N" to path and returns true if success, returns false otherwise
bool Creature::goNorth(Maze &maze) {
    if (maze.IsClear(row - 1, column) && row - 1 < maze.maze_height
        && column < maze.maze_width && !maze.IsVisited(row - 1, column)) {
        maze.MarkAsPath(row, column);
        row--;
        if (row == maze.row_exit && column == maze.column_exit) {
            maze.MarkAsPath(row, column);
            success = true;
        } else {
            success = goNorth(maze);
            if (!success) {
                success = goWest(maze);
                if (!success) {
                    success = goEast(maze);
                    if (!success) {
                        maze.MarkAsVisited(row, column);
                        success = goSouth(maze);
                        row++;
                        if (success) {
                            path += "S";
                        }
                    } else {
                        path += "E";
                    }
                } else {
                    path += "W";
                }
            } else {
                path += "N";
            }
        }
    }
    return success;
}

// If possible, moves the creature to the space directly west of the current
// location. Recursively tries to move to north, west, east, and south.
// Moves back to where it came from if failed to move.
// Adds "W" to path and returns true if success, returns false otherwise
bool Creature::goWest(Maze &maze) {
    if (maze.IsClear(row, column - 1) && row < maze.maze_height &&
        column - 1 < maze.maze_width && !maze.IsVisited(row, column - 1)) {
        maze.MarkAsPath(row, column);
        column--;
        if (row == maze.row_exit && column == maze.column_exit) {
            maze.MarkAsPath(row, column);
            success = true;
        } else {
            success = goNorth(maze);
            if (!success) {
                success = goWest(maze);
                if (!success) {
                    success = goEast(maze);
                    if (!success) {
                        maze.MarkAsVisited(row, column);
                        success = goSouth(maze);
                        column++;
                        if (success) {
                            path += "S";
                        }
                    } else {
                        path += "E";
                    }
                } else {
                    path += "W";
                }
            } else {
                path += "N";
            }
        }
    }
    return success;
}

// If possible, moves the creature to the space directly east of the current
// location. Recursively tries to move to north, west, east, and south.
// Moves back to where it came from if failed to move.
// Adds "E" to path and returns true if success, returns false otherwise
bool Creature::goEast(Maze &maze) {
    if (maze.IsClear(row, column + 1) && row < maze.maze_height &&
        column + 1 < maze.maze_width && !maze.IsVisited(row, column + 1)) {
        maze.MarkAsPath(row, column);
        column++;
        if (row == maze.row_exit && column == maze.column_exit) {
            maze.MarkAsPath(row, column);
            success = true;
        } else {
            success = goNorth(maze);
            if (!success) {
                success = goWest(maze);
                if (!success) {
                    success = goEast(maze);
                    if (!success) {
                        maze.MarkAsVisited(row, column);
                        success = goSouth(maze);
                        column--;
                        if (success) {
                            path += "S";
                        }
                    } else {
                        path += "E";
                    }
                } else {
                    path += "W";
                }
            } else {
                path += "N";
            }
        }
    }
    return success;
}

// If possible, moves the creature to the space directly south of the current
// location. Recursively tries to move to north, west, east, and south.
// Moves back to where it came from if failed to move.
// Adds "S" to path and returns true if success, returns false otherwise
bool Creature::goSouth(Maze &maze) {
    if (maze.IsClear(row + 1, column) && row + 1 < maze.maze_height
        && column < maze.maze_width && !maze.IsVisited(row + 1, column)) {
        maze.MarkAsPath(row, column);
        row++;
        if (row == maze.row_exit && column == maze.column_exit) {
            maze.MarkAsPath(row, column);
            success = true;
        } else {
            success = goNorth(maze);
            if (!success) {
                success = goWest(maze);
                if (!success) {
                    success = goEast(maze);
                    if (!success) {
                        maze.MarkAsVisited(row, column);
                        success = goSouth(maze);
                        row--;
                        if (success) {
                            path += "S";
                        }
                    } else {
                        path += "E";
                    }
                } else {
                    path += "W";
                }
            } else {
                path += "N";
            }
        }
    }
    return success;
}

// reverse path in order to get the correct path
void Creature::reversePath() {
    long n = path.length();
    char c;
    for (int i = 0; i < n / 2; i++) {
        c = path[i];
        path[i] = path[n - i - 1];
        path[n - i - 1] = c;
    }
}
