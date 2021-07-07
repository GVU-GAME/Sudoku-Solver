#ifndef SOLVER.h
#define SOLVER.h

#include <iostream>

using namespace std;

class solver {
    public:
        solver();
    private:
        void solve(int grid[9][9]);
        bool isSolved(int grid[9][9]);
        void printGrid(int grid[9][9]);
};

#endif