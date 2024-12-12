#include <iostream>
#include <vector>
using namespace std;
void solve(vector<vector<int>>& ans ,vector<int> output, int n, int k, int start) {
    if(output.size() == k) {
        ans.push_back(output);
        return;
    }
    for(int i = start; i <= n; i++) {
        output.push_back(i);
        solve(ans, output, n, k, i + 1);
        output.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> output;
    solve(ans, output, n, k, 1);
    return ans;
}
int main() {
    int n = 100, k = 3;
    vector<vector<int>> solution = combine(n, k);
    cout << "[";
    for(int i = 0; i < solution.size(); i++) {
        cout << "[";
        for(int j = 0; j < solution[i].size(); j++) {
            if(j == solution[i].size() - 1) {
                cout << solution[i][j];
                continue;
            }
            cout << solution[i][j] << ",";
        }
        if(i == solution.size() - 1) {
            cout << "]";
            continue;
        }
        cout << "],";
    }
    cout << "]";
    return 0;
}