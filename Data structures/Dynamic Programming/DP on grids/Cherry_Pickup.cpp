#include <iostream>
#include <vector>
using namespace std;

// Recursion
int solve1(vector<vector<int>> &grid, int m, int n, int i, int j1, int j2) {
    if(i == m - 1) {
        if(j1 != j2) return grid[i][j1] + grid[i][j2];
        else return grid[i][j1];
    }
    vector<int> moves = {-1, 0, 1};
    int ans = -10e5;
    for(int I = 0; I < 3; I++) {
        int pos1 = j1 + moves[I];
        if(pos1 < 0 || pos1 >= n) continue;
        for(int J = 0; J < 3; J++) {
            int pos2 = j2 + moves[J];
            if(pos2 >= 0 && pos2 < n) {
                if(j1 != j2)
                    ans = max(ans, grid[i][j1] + grid[i][j2] + solve1(grid, m, n, i + 1, pos1, pos2));
                else {
                    ans = max(ans, grid[i][j1] + solve1(grid, m, n, i + 1, pos1, pos2));
                }
            }
        }
    }

    return ans;
}
int maximumChocolates1(int r, int c, vector<vector<int>> &grid) {
    return solve1(grid, r, c, 0, 0, c - 1);
}


// Memoization
int solve2(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int m, int n, int i, int j1, int j2) {
    if(i == m - 1) {
        if(j1 != j2) return grid[i][j1] + grid[i][j2];
        else return grid[i][j1];
    }
    vector<int> moves = {-1, 0, 1};
    int ans = -10e5;
    for(int I = 0; I < 3; I++) {
        int pos1 = j1 + moves[I];
        if(pos1 < 0 || pos1 >= n) continue;
        for(int J = 0; J < 3; J++) {
            int pos2 = j2 + moves[J];
            if(pos2 >= 0 && pos2 < n) {
                if(j1 != j2)
                    if(dp[i + 1][pos1][pos2] != -1) 
                        ans = max(ans, grid[i][j1] + grid[i][j2] + dp[i + 1][pos1][pos2]);
                    else
                        ans = max(ans, grid[i][j1] + grid[i][j2] + solve2(grid, dp, m, n, i + 1, pos1, pos2));
                else {
                    if(dp[i + 1][pos1][pos2] != -1) 
                        ans = max(ans, grid[i][j1] + dp[i + 1][pos1][pos2]);
                    else
                        ans = max(ans, grid[i][j1] + solve2(grid, dp, m, n, i + 1, pos1, pos2));
                }
            }
        }
    }

    return dp[i][j1][j2] = ans;
}
int maximumChocolates2(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
    return solve2(grid, dp, r, c, 0, 0, c - 1);
}


// Tabulation
int maximumChocolates3(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));

    for(int i = 0; i < c; i++) {
        for(int j = 0; j < c; j++) {
            if(i != j) dp[r - 1][i][j] = grid[r - 1][i] + grid[r - 1][j];
            else dp[r - 1][i][j] = grid[r - 1][i];
        }
    }

    for(int i = r - 2; i >= 0; i--) {
        for(int j1 = 0; j1 < c; j1++) {
            for(int j2 = 0; j2 < c; j2++) {
                vector<int> moves = {-1, 0, 1};
                int ans = -10e5;
                for(int I = 0; I < 3; I++) {
                    int pos1 = j1 + moves[I];
                    if(pos1 < 0 || pos1 >= c) continue;
                    for(int J = 0; J < 3; J++) {
                        int pos2 = j2 + moves[J];
                        if(pos2 >= 0 && pos2 < c) {
                            if(j1 != j2) 
                                ans = max(ans, grid[i][j1] + grid[i][j2] + dp[i + 1][pos1][pos2]);
                            else
                                ans = max(ans, grid[i][j1] + dp[i + 1][pos1][pos2]);
                        }
                    }
                }
                dp[i][j1][j2] = ans;
            }
        }
    }

    return dp[0][0][c - 1];
}


// Space Optimisation
int maximumChocolates4(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));

    for(int i = 0; i < c; i++) {
        for(int j = 0; j < c; j++) {
            if(i != j) dp[1][i][j] = grid[r - 1][i] + grid[r - 1][j];
            else dp[1][i][j] = grid[r - 1][i];
        }
    }

    for(int i = r - 2; i >= 0; i--) {
        for(int j1 = 0; j1 < c; j1++) {
            for(int j2 = 0; j2 < c; j2++) {
                vector<int> moves = {-1, 0, 1};
                int ans = -10e5;
                for(int I = 0; I < 3; I++) {
                    int pos1 = j1 + moves[I];
                    if(pos1 < 0 || pos1 >= c) continue;
                    for(int J = 0; J < 3; J++) {
                        int pos2 = j2 + moves[J];
                        if(pos2 >= 0 && pos2 < c) {
                            if(j1 != j2) 
                                ans = max(ans, grid[i][j1] + grid[i][j2] + dp[1][pos1][pos2]);
                            else
                                ans = max(ans, grid[i][j1] + dp[1][pos1][pos2]);
                        }
                    }
                }
                dp[0][j1][j2] = ans;
            }
        }
        for(int j1 = 0; j1 < c; j1++) {
            for(int j2 = 0; j2 < c; j2++) {
                dp[1][j1][j2] = dp[0][j1][j2];
            }
        }
    }

    return dp[1][0][c - 1];
}

int main() {
    vector<vector<int>> grid = {
        {1, 5, 2, 2},
        {2, 4, 5, 1},
        {4, 4, 4, 5},
        {2, 0, 4, 0}
    };

    cout << maximumChocolates1(grid.size(), grid[0].size(), grid) << endl;
    cout << maximumChocolates2(grid.size(), grid[0].size(), grid) << endl;
    cout << maximumChocolates3(grid.size(), grid[0].size(), grid) << endl;
    cout << maximumChocolates4(grid.size(), grid[0].size(), grid);

    return 0;
}