#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int>& nums, vector<int> output, vector<vector<int>>& ans, int index) {
    if(index == nums.size()) {
        ans.push_back(output);
        return;
    }
    solve(nums, output, ans, index + 1);
    output.push_back(nums[index]);
    solve(nums, output, ans, index + 1);
}
vector<vector<int>> subSets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, ans, index);
    return ans;
}
int main() {
    vector<int> set = {8, 4, 7, 2};
    vector<vector<int>> superSet = subSets(set);
    cout << superSet.size() << endl;
    cout << "{";
    for(int i = 0; i < superSet.size(); i++) {
        cout << "{";
        for(int j = 0; j < superSet[i].size(); j++) {
            if(j == superSet[i].size() - 1) {
                cout << superSet[i][j];
                continue;
            }
            cout << superSet[i][j] << ", ";
        }
        if(i == superSet.size() - 1) {
            cout << "}";
            continue;
        }
        cout << "}, ";
    }
    cout << "}";
    return 0;
}