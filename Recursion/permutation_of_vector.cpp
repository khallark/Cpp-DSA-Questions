#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve(vector<int> nums, vector<vector<int>>& ans, int index) {
    if(index == nums.size()) {
        ans.push_back(nums);
        return;
    }
    for(int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        solve(nums, ans, index + 1);
        swap(nums[index], nums[i]);
    }       
}
vector<vector<int>> permute(vector<int>& nums) {
    if(nums.size() == 0) return {};
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, ans, index);
    return ans;
}
int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 ,15, 16, 17, 18, 19, 20};
    vector<vector<int>> solution = permute(a);
    cout << "[";
    for(int i = 0; i < solution.size(); i++) {
        cout << "{";
        for(int j = 0; j < solution[i].size(); j++) {
            if(j == solution[i].size() - 1) {
                cout << solution[i][j];
                continue;
            }
            cout << solution[i][j] << ",";
        }
        if(i == solution.size() - 1) {
            cout << "}";
            continue;
        }
        cout << "},";
    }
    cout << "]";
    return 0;
}