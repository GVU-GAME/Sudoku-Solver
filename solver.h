#ifndef SOLVER.h
#define SOLVER.h

#define MAX 9
#define EMPTY 0

#include <iostream>

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
};

#endif