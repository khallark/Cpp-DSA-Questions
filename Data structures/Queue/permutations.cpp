#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(vector<int> a, vector<vector<int>>& ans, vector<int> output) {
    if(a.size() == 0) {
        ans.push_back(output);
        return;
    }
    for(int i = 0; i < a.size(); i++) {
        if(i != 0 && a[i] == a[i - 1]) {
            continue;
        }
        vector<int>temp = a;
        temp.erase(find(temp.begin(), temp.end(), temp[i]));
        output.push_back(a[i]);
        solve(temp, ans, output);
        output.pop_back();
    }
}
vector<vector<int>> permutations(vector<int> a) {
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    vector<int> output;
    solve(a, ans, output);
    return ans;
}
int main() {
    vector<int> a = {3, 1, 2};
    vector<vector<int>> ans = permutations(a);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}