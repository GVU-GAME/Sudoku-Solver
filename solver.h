#ifndef SOLVER
#define SOLVER

#define MAX 9
#define EMPTY 0

#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

class solver {
    public:
        solver();
    private:
        void solve(int grid[MAX][MAX]);
        bool isSolved(int grid[MAX][MAX]);
        void printGrid(int grid[MAX][MAX]);
        bool isEmpty(int grid[MAX][MAX], int &, int &);
        bool isValidSpot(int grid[MAX][MAX], int, int, int);
        bool checkHori(int grid[MAX][MAX], int, int);
        bool checkVert(int grid[MAX][MAX], int, int);
        bool checkBox(int grid[MAX][MAX], int, int, int);
        void getPuzzel();
};

#endif