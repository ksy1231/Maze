//
//  main.cpp
//  Maze
//
//  Created by Soo Yun Kim on 4/1/20.
//  Copyright © 2020 Soo Yun Kim. All rights reserved.
//

#include "creature.hpp"

#include <iostream>

void testMaze1() {
    Maze m1("maze1.txt");
    Creature c1(4, 0);
    string path = c1.Solve(m1);
    cout << "m1's path: " << path << endl;
    cout << m1 << endl;
}

void testMaze2() {
    Maze m2("maze2.txt");
    Creature c2(1, 13);
    string path = c2.Solve(m2);
    cout << "m2's path: " << path << endl;
    cout << m2 << endl;
}

int main(int argc, const char * argv[]) {
    testMaze1();
    testMaze2();
    cout << "Done." << endl;
    return 0;
}
