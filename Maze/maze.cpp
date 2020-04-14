//
//  maze.cpp
//  Maze
//
//  Created by Soo Yun Kim on 4/1/20.
//  Copyright © 2020 Soo Yun Kim. All rights reserved.
//

#include "maze.hpp"

// follows the format provided above printing the maze
ostream &operator<<(ostream &out, const Maze &maze) {
    for (int r = 0; r < maze.maze_height; r++) {
        for (int c = 0; c < maze.maze_width; c++) {
            out << maze.field[r][c];
        }
        out << endl;
    }
    return out;
}

// Maze constructor requiring a valid file name
Maze::Maze(string mazeFile) {
    ifstream fin(mazeFile);
    
    if (!fin.is_open()) {
        cout << "Input file opening failed." << endl;
    }
    
    while (fin.eof() == false) {
        fin >> maze_width >> maze_height >> row_exit >> column_exit;
        
        string str;
        int r = 0;
        int c;
        while (getline(fin, str)) {
            if (str == "\r") {
                continue;
            } else {
                for (c = 0; c < maze_width; c++) {
                    field[r][c] = str[c];
                }
                r++;
            }
        }
    }
    fin.close();
}

// destructor
Maze::~Maze() {}

// check the given square is clear
// returns true if given space in the maze is clear, false otherwise
bool Maze::IsClear(int row, int column) const {
    if (field[row][column] == ' ') {
        return true;
    }
    return false;
}

// check the given square is wall
// returns true if given space in the maze is a wall, false otherwise
bool Maze::IsWall(int row, int column) const {
    if (field[row][column] == 'x') {
        return true;
    }
    return false;
}

// check the given square lies on the path to the exit
// returns true if given space in the maze is a path, false otherwise
bool Maze::IsPath(int row, int column) const {
    if (field[row][column] == '*') {
        return true;
    }
    return false;
}

// check the given square was visited, but going that way led to an impasse
// returns true if given space in the maze has been visited, false otherwise
bool Maze::IsVisited(int row, int column) const {
    if (field[row][column] == '+') {
        return true;
    }
    return false;
}

// mark the maze with *
void Maze::MarkAsPath(int row, int column) {
    field[row][column] = '*';
}

// mark the maze with +
void Maze::MarkAsVisited(int row, int column) {
    field[row][column] = '+';
}
