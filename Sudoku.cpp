//
//  Sudoku.cpp
//
//  Created by Alessandra Rodriguez on 4/8/21.
//

#include "Sudoku.h"

int const WIDTH = 40;

Sudoku::Sudoku() {
}

void Sudoku::printLine(ostream& os) const {
    for (int i = 0; i < WIDTH; i++) {
        os << "-";
    }
    os << endl;
}

void Sudoku::print(ostream& os) const {
    printLine(os);
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (!empty(r, c)) {
                os << setw(2) << board[r][c] << " |";
            }
            else if (empty(r, c)) {
                os << setw(2) << "   |";
            }
            
            
            if (((c+1) % 3 == 0) && (c != 0)) {
                os << "|" << setw(1);
            }
        }
        os << endl;
        
        if (((r+1) % 3 == 0) && (r != 0)) {
            printLine(os);
        }
    }
    os << endl;
}

int Sudoku::getUserInput() {
    int input;
    
    do {
        cin >> input;
        if (!((input >= 6) && (input <= 60))) {
            cout << "*You must choose a number between 6 through 60*" << endl;
        }
        
    } while(!((input >= 6) && (input <= 60)));
    
    return input;
}

void Sudoku::printMenu(ostream&) {
    cout << "Hello, welcome to Alessandra's sudoku!" << endl << endl;
    cout << "How many numbers would you like to disapear?" << endl;
    cout << "*You must choose a number between 6 through 60*" << endl;
}

void Sudoku::removeNums(int num) {
    int r, c;
    bool onList;
    srand(time(0));
    
    for (int i = 0; i < num; i++) {
        
        do {
            onList = false;
                
            r = rand() % 9;
            c = rand() % 9;
            
            if (empty(r, c)) {
                onList = true;
            }
            
            if (!empty(r, c)) {
                board[r][c] = 0;
            }
            
        } while (onList);
        
    }
    
    
}

void Sudoku::init() {
    int a;
    printMenu(cout);
    a = getUserInput();
    removeNums(a);
}

bool Sudoku::empty(int r, int c) const{
    bool ifEmpty = true;
    
    if ((board[r][c]) != 0) {
        ifEmpty = false;
    }
    
    return ifEmpty;
}

void Sudoku::updateMatrix() {
    int r, c, g;
    
    do {
        cout << "Please enter: ROW COLUMN GUESS ";
        cin >> r >> c >> g;
        
        if (!((r < 10) && (r > 0) && (c < 10) && (c > 0) && (g < 10) && (g > 0))){
            cout << "ERROR: Entry not in range (1-9). Try again." << endl;
        }
        else if (!isSafe(r - 1, c - 1, g)) {
            cout << "Hmm... good try but that's incorrect. Try again." << endl;
        }
        else {
            board[r - 1][c - 1] = g;
            print(cout);
        }
        
    } while (!isComplete());
    
    cout << "Thank you for playing! :)" << endl;
    
}

bool Sudoku::isComplete() {
    bool done = true;
    
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (empty(r,c)) {
                done = false;
            }
        }
    }
    
    return done;
}

bool Sudoku::rowSum(int r, int g) const{
    bool ifRow = true;
    int sum = 0;
    
    for (int i = 0; i < 9; i++) {
        sum += board[r][i];
    }
    
    sum += g;
    
    if (sum > 45) {
        ifRow = false;
    }
    
    return ifRow;
}

bool Sudoku::colSum(int c, int g) const{
    bool ifCol = true;
    int sum = 0;
    
    for (int i = 0; i < 9; i++) {
        sum += board[i][c];
    }
    
    sum += g;
    
    if (sum > 45) {
        ifCol = false;
    }
    
    return ifCol;
}

bool Sudoku::sqSum (int r, int c, int g) const {
    bool ifSq = true;
    int row = r - (r % 3);
    int col = c - (c % 3);
    int sum = 0;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += board[row + i][col + j];
        }
    }
    
    sum += g;
    
    if (sum > 45) {
        ifSq = false;
    }
    
    return ifSq;
}

bool Sudoku::rowDup (int r, int g) const {
    bool check = false;
    
    for (int i = 0; i < 9; i++) {
        if (g == board[r][i]) {
            check = true;
        }
    }
    
    return check;
}

bool Sudoku::colDup (int c, int g) const {
    bool check = false;
    
    for (int i = 0; i < 9; i++) {
        if (g == board[i][c]) {
            check = true;
        }
    }
    
    return check;
}

bool Sudoku::sqDup (int r, int c, int g) const {
    bool check = false;
    int row = r - (r % 3);
    int col = c - (c % 3);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (g == board[row + i][col + j]) {
                check = true;
            }
        }
    }
    
    return check;
}

bool Sudoku::isSafe (int r, int c, int g) const {
    bool safe = true;
    
    if (!rowSum(r, g) || !colSum(c, g) || !sqSum(r, c, g) || rowDup(r,g) || colDup(c, g) || sqDup(r, c, g)) {
        safe = false;
    }
    
    return safe;
}

void Sudoku::createBoard() {
    srand(time(0));
    int puzzle = rand() % 4;
    
    int boardOne[SIZE][SIZE] = {{4, 3, 5, 2, 6, 9, 7, 8, 1},
                                {6, 8, 2, 5, 7, 1, 4, 9, 3},
                                {1, 9, 7, 8, 3, 4, 5, 6, 2},
                                {8, 2, 6, 1, 9, 5, 3, 4, 7},
                                {3, 7, 4, 6, 8, 2, 9, 1, 5},
                                {9, 5, 1, 7, 4, 3, 6, 2, 8},
                                {5, 1, 9, 3, 2, 6, 8, 7, 4},
                                {2, 4, 8, 9, 5, 7, 1, 3, 6},
                                {7, 6, 3, 4, 1, 8, 2, 5, 9}};
    
    int boardTwo[SIZE][SIZE] = {{1, 5, 2, 4, 8, 9, 3, 7, 6},
                                {7, 3, 9, 2, 5, 6, 8, 4, 1},
                                {4, 6, 8, 3, 7, 1, 2, 9, 5},
                                {3, 8, 7, 1, 2, 4, 6, 5, 9},
                                {5, 9, 1, 7, 6, 3, 4, 2, 8},
                                {2, 4, 6, 8, 9, 5, 7, 1, 3},
                                {9, 1, 4, 6, 3, 7, 5, 8, 2},
                                {6, 2, 5, 9, 4, 8, 1, 3, 7},
                                {8, 7, 3, 5, 1, 2, 9, 6, 4}};
    
    int boardThree[SIZE][SIZE] = {{1, 2, 3, 6, 7, 8, 9, 4, 5},
                                  {5, 8, 4, 2, 3, 9, 7, 6, 1},
                                  {9, 6, 7, 1, 4, 5, 3, 2, 8},
                                  {3, 7, 2, 4, 6, 1, 5, 8, 9},
                                  {6, 9, 1, 5, 8, 3, 2, 7, 4},
                                  {4, 5, 8, 7, 9, 2, 6, 1, 3},
                                  {8, 3, 6, 9, 2, 4, 1, 5, 7},
                                  {2, 1, 9, 8, 5, 7, 4, 3, 6},
                                  {7, 4, 5, 3, 1, 6, 8, 9, 2}};
    
    int boardFour[SIZE][SIZE] = {{5, 8, 1, 6, 7, 2, 4, 3, 9},
                                 {7, 9, 2, 8, 4, 3, 6, 5, 1},
                                 {3, 6, 4, 5, 9, 1, 7, 8, 2},
                                 {4, 3, 8, 9, 5, 7, 2, 1, 6},
                                 {2, 5, 6, 1, 8, 4, 9, 7, 3},
                                 {1, 7, 9, 3, 2, 6, 8, 4, 5},
                                 {8, 4, 5, 2, 1, 9, 3, 6, 7},
                                 {9, 1, 3, 7, 6, 8, 5, 2, 4},
                                 {6, 2, 7, 4, 3, 5, 1, 9, 8}};
    
    int boardFive[SIZE][SIZE] = {{2, 7, 6, 3, 1, 4, 9, 5, 8},
                                 {8, 5, 4, 9, 6, 2, 7, 1, 3},
                                 {9, 1, 3, 8, 7, 5, 2, 6, 4},
                                 {4, 6, 8, 1, 2, 7, 3, 9, 5},
                                 {5, 9, 7, 4, 3, 8, 6, 2, 1},
                                 {1, 3, 2, 5, 9, 6, 4, 8, 7},
                                 {3, 2, 5, 7, 8, 9, 1, 4, 6},
                                 {6, 4, 1, 2, 5, 3, 8, 7, 9},
                                 {7, 8, 9, 6, 4, 1, 5, 3, 2}};
    
    switch (puzzle) {
        case 0:
            for (int r = 0; r < SIZE; r++) {
                for (int c = 0; c < SIZE; c++) {
                    board[r][c] = boardOne[r][c];
                }
            }
            break;
            
        case 1:
            for (int r = 0; r < SIZE; r++) {
                for (int c = 0; c < SIZE; c++) {
                    board[r][c] = boardTwo[r][c];
                }
            }
            break;
            
        case 2:
            for (int r = 0; r < SIZE; r++) {
                for (int c = 0; c < SIZE; c++) {
                    board[r][c] = boardThree[r][c];
                }
            }
            break;
            
        case 3:
            for (int r = 0; r < SIZE; r++) {
                for (int c = 0; c < SIZE; c++) {
                    board[r][c] = boardFour[r][c];
                }
            }
            break;
            
        case 4:
            for (int r = 0; r < SIZE; r++) {
                for (int c = 0; c < SIZE; c++) {
                    board[r][c] = boardFive[r][c];
                }
            }
            break;

        default:
            break;
    }
    
    
}

/*void Sudoku::createBoard() {
    int num;
    
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            do {
                num = ((rand() % 9) + 1);
                
                if (isSafe(r, c, num)) {
                    board[r][c] = num;
                }
                
            } while (empty(r, c));
            
        }
    }
    
    for (int r = 3; r < 6; r++) {
        for (int c = 3; c < 6; c++) {
            do {
                num = ((rand() % 9) + 1);
                
                if (isSafe(r, c, num)) {
                    board[r][c] = num;
                }
                
            } while (empty(r, c));
            
        }
    }
    
    for (int r = 6; r < 9; r++) {
        for (int c = 6; c < 9; c++) {
            do {
                num = ((rand() % 9) + 1);
                
                if (sqSum(r, c, num) && !sqDup(r, c, num)) {
                    board[r][c] = num;
                }
                
            } while (empty(r, c));
            
        }
    }
    
    int g = 1;
    for (int r = 0; r < 3; r++) {
        for (int c = 3; c < 9; c++) {
            do {
                if (isSafe(r, c, g)) {
                    board[r][c] = g;
                }
                g++;
                if (g > 9) {
                    g = 1;
                }
            } while (empty(r, c));
        }
    }
    
    for (int r = 3; r < 6; r++) {
        for (int c = 3; c < 6; c++) {
            for (int num = 1; num <= 9; num++) {
                if (isSafe(r, c, num)) {
                    board[r][c] = num;
                }
            }
            
        }
    }
}

void Sudoku::createBoard2() {
    
    for (int r = 0; r < 9; r++) {
        for (int i = 1; i < 10; i++) {
            if (rowDup(r, i)) {
                <#statements#>
            }
        }
    }
    
    
}*/
