#include <iostream>
#include <vector>
#include <set>
using namespace std;
void solve(vector<int> candidates, int target, vector<vector<int>>& ans, vector<int> output, int start) {
    if(target == 0) {
        ans.push_back(output);
        return;
    }
    if(target < 0) return;
    for(int i = start; i < candidates.size(); i++) {
        if(candidates[i] <= target) {
            output.push_back(candidates[i]);
            solve(candidates, target - candidates[i], ans, output, i);
            output.pop_back();
        }
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> output;
    int sum = 0;
    solve(candidates, target, ans, output, 0);
    return ans;
}
int main() {
    vector<int> arr = {2,3,6,7};
    vector<vector<int>> solution = combinationSum(arr, 40);
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