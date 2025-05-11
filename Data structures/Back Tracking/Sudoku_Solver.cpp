#include <iostream>
#include <vector>
using namespace std;

pair<int, int> Sub_Grid(int i, int j) {
    int a, b;

    if(i < 3) a = 0;
    else if(i > 2 && i < 6) a = 3;
    else if(i > 5 && i < 9) a = 6;

    if(j < 3) b = 0;
    else if(j > 2 && j < 6) b = 3;
    else if(j > 5 && j < 9) b = 6;

    return make_pair(a, b);
}

int no_error_check(vector<vector<int>> grid, int i, int j, int num) {
    vector<bool> dups(9, false);

    for(int x = 0; x < 9; x++) {
        if(x == i) continue;
        if(grid[x][j] == 0) continue;
        if(dups[grid[x][j] - 1] || num == grid[x][j]) {
            return false;
        }
        dups[grid[x][j] - 1] = true;
    }

    dups = vector<bool>(9, false);
    for(int x = 0; x < 9; x++) {
        if(x == j) continue;
        if(grid[i][x] == 0) continue;
        if(dups[grid[i][x] - 1] || num == grid[i][x]) {
            return false;
        }
        dups[grid[i][x] - 1] = true;
    }

    dups = vector<bool>(9, false);
    pair<int, int> p = Sub_Grid(i, j);
    int a = p.first, b = p.second;
    for(int x = a; x < a + 3; x++) {
        for(int y = b; y < b + 3; y++) {
            if(x == i && y == j) continue;
            if(grid[x][y] == 0) continue;
            if(dups[grid[x][y] - 1] || num == grid[x][y]) {
                return false;
            }
            dups[grid[x][y] - 1] = true;
        }
    }
    return true;
}

void solve(vector<vector<vector<int>>>& cont, vector<vector<int>> grid, int i, int j) {
    bool do_recursion = false;
    bool no_error = true;
    int x, y;

    for(x = i; x < 9; x++) {
        bool br = false;
        for(y = x == i ? j : 0; y < 9; y++) {
            if(grid[x][y] == 0) {
                do_recursion = true;
                br = true;
                break;
            }
            if(!no_error_check(grid, x, y, grid[x][y])) {
                no_error = false;
                br = true;
                break;
            }
        }
        if(br) break;
    }

    if(do_recursion) {
        for(int num = 1; num < 10; num++) {
            if(no_error_check(grid, x, y, num)) {
                grid[x][y] = num;
                solve(cont, grid, x, y);
            }
        }
    }
    else if(no_error) {
        cont.push_back(grid);
    }
} 

void SolveSudoku(vector<vector<vector<int>>>& grid, vector<vector<int>> Grid) {
    solve(grid, Grid, 0, 0);
}

void printGrid (vector<vector<vector<int>>> Supergrid) {
    for(int k = 0; k < Supergrid.size(); k++) {
        vector<vector<int>> grid = Supergrid[k];
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if((j + 1) % 3) cout << grid[i][j] << " ";
                else cout << grid[i][j] << "   ";
            }
            if((i + 1) % 3) cout << endl;
            else cout << endl << endl;
        }
        cout << "---------------------" << endl;
    }
}

int main() {
    vector<vector<int>> sudoku = {
        {8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 6, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 9, 0, 2, 0, 0},
        {0, 5, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 4, 5, 7, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 3, 0},
        {0, 0, 1, 0, 0, 0, 0, 6, 8},
        {0, 0, 8, 5, 0, 0, 0, 1, 0},
        {0, 9, 0, 0, 0, 0, 4, 0, 0}
    };
    vector<vector<vector<int>>> Grid;
    SolveSudoku(Grid, sudoku);
    printGrid(Grid);
    return 0;
}