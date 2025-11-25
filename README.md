Modular Tic Tac Toe – Project Report

1. Abstract

This project implements a Modular Tic Tac Toe game in C, designed using multiple functions to improve readability, structure, and reusability. The game allows two players to play Tic Tac Toe in a 3×3 grid, checks for valid input, detects winning combinations, and declares the result (Win / Draw). The modular approach ensures that each task—such as displaying the board, taking input, checking status—is handled by separate functions.


2. Features of the Program

Interactive two-player Tic Tac Toe game

Modular structure using multiple functions

Displays a 3×3 game board

Checks valid moves

Automatically detects:

Player X wins

Player O wins

Draw


Allows replay by resetting the board

Clear and simple interface for beginners



3. Technical Requirements

Hardware Requirements

Any laptop/desktop

Minimum 2GB RAM

Any processor capable of running C compiler (Intel/AMD/ARM)


Software Requirements

C Compiler (GCC / MinGW / Turbo C / Clang)

Code editor (VS Code, Dev-C++, CodeBlocks, Notepad++, etc.)

Operating System: Windows / Linux / MacOS



4. Functional Requirements

Functional Modules

1. displayBoard()

Shows the current Tic Tac Toe grid



2. playerMove()

Accepts and validates player input



3. checkWin()

Checks all rows, columns, and diagonals for a win



4. checkDraw()

Determines if the board is full



5. resetBoard()

Clears the board for a new match



6. main()

Controls the overall game flow




5. How to Run the C Program

If using GCC (Windows/Linux/macOS):

gcc tictactoe.c -o tictactoe
./tictactoe

If using VS Code:

1. Install C/C++ extension


2. Open your .c file


3. Press Run or use terminal:

gcc tictactoe.c -o game
./game



If using Turbo C++ (old):

Open file → Compile → Run (Ctrl + F9)
