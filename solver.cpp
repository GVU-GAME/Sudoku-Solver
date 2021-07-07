#include "solver.h"

//gets the sudoku board to solve
solver::solver() {
    int grid[MAX][MAX] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 3, 0, 8, 5},
                      {0, 0, 1, 0, 2, 0, 0, 0, 0},
                      {0, 0, 0, 5, 0, 7, 0, 0, 0},
                      {0, 0, 4, 0, 0, 0, 1, 0, 0},
                      {0, 9, 0, 0, 0, 0, 0, 0, 0},
                      {5, 0, 0, 0, 0, 0, 0, 7, 3},
                      {0, 0, 2, 0, 1, 0, 0, 0, 0},
                      {0, 0, 0, 0, 4, 0, 0, 0, 9}};
    solve(grid);
}

//checks for empty space, increments the row and col too the empty space
bool solver::isEmpty(int grid[MAX][MAX], int &row, int &col) {
    for(row = 0; row < MAX; row++) {
        for(col = 0; col < MAX; col++) {
            if(grid[row][col] == EMPTY) {
                return true;
            }
        }
    }

    return false;
}

//returns if the board is solved or not
bool solver::isSolved(int grid[MAX][MAX]) {
    int row, col;

    //checks if there is any empty spaces left
    if(!isEmpty(grid, row, col)){
        return true;
    }

    //gets numbers 1 to 9 to place on the board
    for(int num = 1; num <= MAX; num++) {
        //code
    }
}

//prints the game board
void solver::printGrid(int grid[MAX][MAX]) {
    for(int row = 0; row < MAX; row++) {
        for(int col = 0; col < MAX; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

//checks if the board is solveable
void solver::solve(int grid[MAX][MAX]){
    if(isSolved(grid)) {
        printGrid(grid);
    } else {
        cout << "Not Solveable!" << endl;
    }
}