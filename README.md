# Console Sudoku Game

## Description
This is a console-based Sudoku game implemented in C++. It generates Sudoku boards, initializing the game, and allowing users to make guesses to complete the board. Users can choose their difficulty and feedback will be given if the rules of the game are violated.

## Features
* Game Initialization: Players can choose the number of missing board values
* User Input: Players can input their guesses for each cell on the Sudoku board
* Validation: The game validates user inputs and ensures they conform to Sudoku rules
* Completion Check: The game checks if the Sudoku board is complete after each move
* Game End: The game ends when the Sudoku board is successfully completed

## Usage (Linux/macOS)
1. Clone this repo locally
2. Compile g++ main.cpp Sudoku.cpp -o SudokuGame
2. Run: ./SudokuGame
3. Follow the on-screen instructions

## File Organization
* Sudoku.h: Header file containing the class definition for the Sudoku game
* Sudoku.cpp: Implementation file with the member function definitions for the Sudoku class
* main.cpp: Main program file where the Sudoku game is instantiated and played

## Future Improvements
* Random Board Generation: Currently, the game utilizes pre-defined Sudoku boards for players to solve. A planned improvement includes implementing a random board generation algorithm

* UI Enhancements: A planned improvement includes created a more visually appealing and user-friendly user experience
