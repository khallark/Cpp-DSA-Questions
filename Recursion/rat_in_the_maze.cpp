#include <iostream>
#include <vector>
using namespace std;
void solve(vector<vector<int>> m, int n, int i, int j, string output, vector<string>& ans) {
    if(i == -1 || i == n || j == -1 || j == n || m[i][j] == 0) {
        return;
    }
    if(i == n - 1 && j == n - 1) {
        ans.push_back(output);
        return;
    }
    m[i][j] = 0;
    solve(m, n, i + 1, j, output + 'D', ans);
    solve(m, n, i, j - 1, output + 'L', ans);
    solve(m, n, i, j + 1, output + 'R', ans);
    solve(m, n, i - 1, j, output + 'U', ans);
    m[i][j] = 1;
}
vector<string> findPath(vector<vector<int>>& m, int n) {
    vector<string> ans;
    int i = 0;
    int j = 0;
    string output = "";
    if(m[0][0] == 0) return ans;
    solve(m, n, i, j, output, ans);
    return ans;
}
int main() {
    vector<vector<int>> maze = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 1, 1}};
    int n = maze.size();
    vector<string> paths = findPath(maze, n);
    cout << "[";
    for(int i = 0; i < paths.size(); i++) {
        if(i == paths.size() - 1) {
            cout << "\"" << paths[i] << "\"";
            continue;
        }
        cout << "\"" << paths[i] << "\"" << ",";
    }
    cout << "]" << endl;
    return 0;
}