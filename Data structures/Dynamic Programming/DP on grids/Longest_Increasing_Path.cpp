#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> mat;
vector<vector<int>> dp;
int m, n;
vector<int>row;
vector<int>col;

int dfs(int i, int j) {
    if(dp[i][j] != -1) return dp[i][j];
    int maxLen = 0;
    for(int k = 0; k < 4; k++) {
        int I = i + row[k], J = j + col[k];
        if(I >= 0 and I < m and J >= 0 and J < n and mat[I][J] > mat[i][j]) {
            maxLen = max(maxLen, dfs(I, J));
        }
    }
    return dp[i][j] = maxLen + 1;
}
int longestIncreasingPath(vector<vector<int>> matrix) {
    row = {0, -1, 0, 1};
    col = {-1, 0, 1, 0};
    m = matrix.size(), n = matrix[0].size();
    dp.resize(m, vector<int>(n, -1));
    mat = matrix;
    int ans = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            ans = max(ans, dfs(i, j));
        }
    }   
    return ans;
}

int main() {
    cout << longestIncreasingPath(vector<vector<int>>({{3,4,5},{3,2,6},{2,2,1}}));
    return 0;
}