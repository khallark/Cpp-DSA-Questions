#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
void solve(vector<int> candidates, vector<int> output, vector<vector<int>>& ans, int target, int index) {
    if(target == 0) {
        ans.push_back(output);
        return;
    }
    for(int i = index; i < candidates.size(); i++) {
        if(i > index && candidates[i] == candidates[i - 1]) continue;
        if(candidates[i] <= target) {
            output.push_back(candidates[i]);
            solve(candidates, output, ans, target - candidates[i], i + 1);
            output.pop_back();
        }
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end()); // Helps avoiding duplicate combinations
    vector<vector<int>> ans;
    vector<int> output;
    solve(candidates, output, ans, target, 0);
    return ans;
}
int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> solution = combinationSum2(candidates, 2);
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