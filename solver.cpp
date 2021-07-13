#include "solver.h"

//gets the sudoku board to solve
void rules();

solver::solver() {
    rules();
    getPuzzel(); 
}

//explains how to use the program
void rules() {
    cout << "\n\t====How To Use====\n" << endl;
    cout << "1. Enter row by row of your sudoku puzzel" << endl;
    cout << "2. Make sure that each number is entered with a space inbetween (1 2 3 etc)" << endl;
    cout << "3. For any empty squares on your puzzel enter the number 0" << endl;
    cout << "\n\t==================\n" << endl;
}

//gets the puzzel from the user
//starts the solving
void solver::getPuzzel() {
    int grid[MAX][MAX];
    
    bool complete = false;
    while(!complete) {
        cout << "\nPlease enter the puzzel row by row" << endl;

        for(int count = 1; count <= MAX; count++) {
            int row[MAX];
            int pos = 0;

            cout << "Enter the numbers of row " << count << endl;
            cout << "Row: ";
            while(cin >> row[pos]) {
                pos++;
                if(pos == MAX) {
                    break;
                }
            }
            memcpy(grid[count-1], row, sizeof(row));
        }

        printGrid(grid);

        char temp;
        cout << "Is this puzzel correct? Y/N: ";
        cin >> temp;
        if(tolower(temp) == 'y') {
            complete == true;
        }
    }
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

//checks if there are any instances of num in the row
bool solver::checkHori(int grid[MAX][MAX], int row, int num) {
    for(int check = 0; check < MAX; check++) {
        if(grid[row][check] == num) {
            return false;
        }
    }
    return true;
}

//checks if there are any instances of num in the col
bool solver::checkVert(int grid[MAX][MAX], int col, int num) {
    for(int check = 0; check < MAX; check++) {
        if(grid[check][col] == num) {
            return false;
        }
    }
    return true;
}

//checks if there are any instances of num in the square
bool solver::checkBox(int grid[MAX][MAX], int row, int col, int num) {
    //checks from top to bottom of box for an instance of num
    for(int cRow = 0; cRow < 3; cRow++) {
        for(int cCol = 0; cCol < 3; cCol++) {
            if(grid[cRow + row][cCol + col] == num) {
                return false;
            }
        }
    }

    return true;
}

//checks if num can be places a place on the grid
bool solver::isValidSpot(int grid[MAX][MAX], int row, int col, int num) {
    return checkHori(grid, row, num) && checkVert(grid, col, num) && checkBox(grid, row - (row % 3), col - (col % 3), num);
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
        //checks if there are no instances of num in the section
        if(isValidSpot(grid, row, col, num)) {
            //sets grid space to num if valid
            grid[row][col] = num;
            //recurse to fill out the remainder of grid
            if(isSolved(grid)) {
                return true;
            }
            grid[row][col] = EMPTY;
        }
    }

    return false;
}

//prints the game board
void solver::printGrid(int grid[MAX][MAX]) {
    for(int row = 0; row < MAX; row++) {
        for(int col = 0; col < MAX; col++) {
            cout << grid[row][col] << " | ";
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