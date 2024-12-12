#include <iostream>
#include <vector>
#include <set>
using namespace std;
void solve(vector<int> nums, vector<vector<int>>& ans, int index) {
    if(index == nums.size()) {
        ans.push_back(nums);
        return;
    }
    set<int> duplicates;
    for(int i = index; i < nums.size(); i++) {
        if(duplicates.count(nums[i])) continue;
        duplicates.insert(nums[i]);
        swap(nums[index], nums[i]);
        solve(nums, ans, index + 1);
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);
    return ans;
}
int main() {
    vector<int> arr = {8,6,7,7};
    vector<vector<int>> solution = permuteUnique(arr);
    cout << solution.size() << endl;
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