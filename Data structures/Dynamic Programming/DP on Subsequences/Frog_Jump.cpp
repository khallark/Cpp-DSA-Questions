#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int n;
vector<int> arr;
set<int> s;
map<int, int> m;
vector<vector<int>> dp;

bool f(int k, int index) {
    if(index == n - 1) return true;
    if(dp[k][index] != -1) return dp[k][index];
    auto it = s.find(arr[index] + k - 1);
    bool km1_index = k > 1 and it != s.end() ? f(k - 1, m[*it]) : false;
    it = s.find(arr[index] + k);
    bool k_index = it != s.end() ? f(k, m[*it]) : false;
    it = s.find(arr[index] + k + 1);
    bool kp1_index = it != s.end() ? f(k + 1, m[*it]) : false;
    return dp[k][index] = km1_index or k_index or kp1_index;
}

bool canCross(vector<int> stones) {
    if(stones[1] > 1) return false;
    dp = vector<vector<int>>(2000, vector<int>(2000, -1));
    n = stones.size();
    arr = stones;
    for(int i = 0; i < n; i++) {
        s.insert(stones[i]);
        m[stones[i]] = i;
    }
    return f(1, 1);
}

int main() {
    cout << canCross(vector<int>({0,1,3,5,6,8,12,17}));
    return 0;
}