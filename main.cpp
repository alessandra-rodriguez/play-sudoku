//
//  main.cpp
//
//  Created by Alessandra Rodriguez on 4/8/21.
//

#include <iostream>
#include "Sudoku.h"
using namespace std;

int main() {
    Sudoku game;
    game.createBoard();
    game.init();
    game.print(cout);
    game.updateMatrix();
    
    return 0;
}
