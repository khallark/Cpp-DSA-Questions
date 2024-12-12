#include <iostream>
#include <vector>
using namespace std;


void solve(vector<vector<int>> m, vector<string>& ans, string output, int size, int i, int j) {
    if(i < 0 || i > size - 1 || j < 0 || j > size - 1 || m[i][j] == 0) {
        return;
    }
    if(i == size - 1 && j == size - 1) {
        ans.push_back(output);
        return;
    }

    m[i][j] = 0;

    solve(m, ans, output + 'D', size, i + 1, j);
    solve(m, ans, output + 'L', size, i, j - 1);
    solve(m, ans, output + 'R', size, i, j + 1);
    solve(m, ans, output + 'U', size, i - 1, j);
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;
    string output = "";
    int i = 0, j = 0;
    solve(m, ans, output, n, i, j);
    return ans;
}

int main() {
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1}, 
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};
    int n = m.size();

    vector<string> ans = findPath(m, n);

    for(auto i : ans) {
        cout << i << " ";
    }

    return 0;
}