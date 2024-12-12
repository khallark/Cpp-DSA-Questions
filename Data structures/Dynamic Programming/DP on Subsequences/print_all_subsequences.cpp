#include <iostream>
#include <matrix.h>
#include <vector>
using namespace std;

void solve(vector<int> &v, vector<vector<int>> &ans, int index) {
    if(index == 0) {
        ans.push_back({v[index]});
        return;
    }
    solve(v, ans, index - 1);
    vector<vector<int>> n;
    int size = ans.size();
    for(int i = 0; i < size; i++) {
        vector<int> temp = ans[i];
        temp.push_back(v[index]);
        ans.push_back(temp);
    }
    ans.push_back({v[index]});
}

vector<vector<int>> all_subsequences(vector<int> &v) {
    vector<vector<int>> temp;
    solve(v, temp, v.size() - 1);
    temp.push_back({});
    vector<vector<int>> ans;
    ans.push_back({});
    for(int i = 1; i <= v.size(); i++) {
        for(auto j : temp) {
            if(j.size() == i) {
                ans.push_back(j);
            }
        }
    }
    return ans;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    vector<vector<int>> ans = all_subsequences(v);    
    cout << "[";
    for(int i = 0; i < ans.size(); i++) {
        cout << "{";
        for(int j = 0; j < ans[i].size(); j++) {
            if(j < ans[i].size() - 1) cout << ans[i][j] << ",";
            else cout << ans[i][j];
        }
        if(i < ans.size() - 1) cout << "}, ";
        else cout << "}";
    }
    cout << "]";
    return 0;
}