//
//  Sudoku.h
//
//  Created by Alessandra Rodriguez on 4/8/21.
//

#ifndef sudoku_h
#define sudoku_h

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

const int SIZE = 9;

class Sudoku {
public:
    Sudoku();
    void print(ostream&) const;
    int getUserInput();
    void init();
    void updateMatrix();
    void createBoard();
    void createBoard2();
    
private:
    int board[SIZE][SIZE] = {0};/*{{1, 2, 3, 4, 5, 6, 7, 8, 9},
        {7, 8, 9, 1, 2, 3, 4, 5, 6},
        {4, 5, 6, 7, 8, 9, 1, 2, 3},
        {3, 1, 2, 8, 4, 5, 9, 6, 7},
        {6, 9, 7, 3, 1, 2, 8, 4, 5},
        {8, 4, 5, 6, 9, 7, 3, 1, 2},
        {2, 3, 1, 5, 7, 4, 6, 9, 8},
        {9, 6, 8, 2, 3, 1, 5, 7, 4},
        {5, 7, 4, 9, 6, 8, 2, 3, 1}};*/
    
    void printLine(ostream&) const;
    void printMenu(ostream&);
    void removeNums(int a);
    int changeBoard();
    bool empty(int r, int c) const;
    bool isComplete();
    bool rowSum(int r, int g) const;
    bool colSum(int c, int g) const;
    bool sqSum (int r, int c, int g) const;
    bool rowDup (int r, int g) const;
    bool colDup (int r, int g) const;
    bool sqDup (int r, int c, int g) const;
    bool isSafe (int r, int c, int g) const;
    
};


#endif /* sudoku_h */
