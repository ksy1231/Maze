//
//  maze.hpp
//  Maze
//
//  Created by Soo Yun Kim on 4/1/20.
//  Copyright © 2020 Soo Yun Kim. All rights reserved.
//

#ifndef maze_hpp
#define maze_hpp

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

class Maze {
    // follows the format provided above printing the maze
    friend ostream &operator<<(ostream &out, const Maze &maze);
    
public:
    // Maze constructor requiring a valid file name
    explicit Maze(string mazeFile);
    // destructor
    ~Maze();
    
    // check the given square is clear
    // returns true if given space in the maze is clear, false otherwise
    bool IsClear(int row, int column) const;
    // check the given square is wall
    // returns true if given space in the maze is a wall, false otherwise
    bool IsWall(int row, int column) const;
    // check the given square lies on the path to the exit
    // returns true if given space in the maze is a path, false otherwise
    bool IsPath(int row, int column) const;
    // check the given square was visited, but going that way led to an impasse
    // returns true if given space in the maze has been visited, false otherwise
    bool IsVisited(int row, int column) const;
    
    // mark the maze with *
    void MarkAsPath(int row, int column);
    // mark the maze with +
    void MarkAsVisited(int row, int column);
    
    // 2-D array that stores maze attributes
    char field[MAX_SIZE][MAX_SIZE];
    // the width and height of the maze
    int maze_width, maze_height;
    // the row and column of the maze's exit
    int row_exit, column_exit;
};

#endif /* maze_hpp */
