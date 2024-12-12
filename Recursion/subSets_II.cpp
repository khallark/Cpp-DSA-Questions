#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
using namespace std;
/*
void solve(vector<int> nums, vector<int> output_set, vector<int> output, vector<vector<int>>& ans, vector<int> dups, int index) {
    if(index == nums.size()) {
        ans.push_back(output);
        return;
    }
    if(dups.count(nums[index]) && output_set.count(nums[index])) {
        output.push_back(nums[index]);
        solve(nums, output_set, output, ans, dups, index + 1);  
    }
    else {
        dups.insert(nums[index]);
        solve(nums, output_set, output, ans, dups, index + 1);
        output.push_back(nums[index]);
        output_set.insert(nums[index]);
        solve(nums, output_set, output, ans, dups, index + 1);
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> output;
    vector<int> output_set;
    vector<int> dups;
    solve(nums, output_set, output, ans, dups, 0);
    return ans;
}
*/

// This is the much better version of the above code.
void solve(vector<int> nums, vector<int> output, vector<vector<int>>& ans, int dups, int index) {
    if(index == nums.size()) {
        ans.push_back(output);
        return;
    }
    if(dups == nums[index] && !output.empty() && output.back() == nums[index]) { // since the array is sorted, instead of making a set, we can directly check if the element is repeated (using dups) and the last element of output == dups (all thanks to the sorted array). Despite of all of these jugaads, this algorithm doesn't even stand in front of the most efficient one.
        output.push_back(nums[index]);
        solve(nums, output, ans, dups, index + 1);
        return;
    }
    dups = nums[index];
    solve(nums, output, ans, dups, index + 1);
    output.push_back(nums[index]);
    solve(nums, output, ans, dups, index + 1);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> output;
    int dups = -11; // basically checks the repeated elements in a sorted vector
    solve(nums, output, ans, dups, 0);
    return ans;
}
int main() {
    vector<int> set_ = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    vector<vector<int>> soulution = subsetsWithDup(set_);
    cout << "[";
    for(int i = 0; i < soulution.size(); i++) {
        cout << "[";
        for(int j = 0; j < soulution[i].size(); j++) {
            if(j == soulution[i].size() - 1) {
                cout << soulution[i][j];
                continue;
            }
            cout << soulution[i][j] << ",";
        }
        if(i == soulution.size() - 1) {
            cout << "]";
            continue;
        }
        cout << "], ";
    }
    cout << "]";
    return 0;
}