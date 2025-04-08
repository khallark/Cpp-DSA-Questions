#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
using namespace std;

class Solution {
private:
    vector<vector<unordered_map<int, int>>> dp;
    vector<int> arr;
    int n;
    int K;
    int lim;
public:
    int solve(int curr, int addOrSub, int altSum) {
        if(curr == n) return -1;
        if(arr[curr] > lim) return -1;
        if(dp[curr][addOrSub].find(altSum) != dp[curr][addOrSub].end())
            return dp[curr][addOrSub][altSum];
        
        int pick = solve(curr + 1, !addOrSub, addOrSub ? altSum - arr[curr + 1] : altSum + arr[curr + 1]);
        int notPick = solve(curr + 1, addOrSub,
        addOrSub ? altSum - arr[curr] + arr[curr + 1] : altSum + arr[curr] - arr[curr + 1]);
        int ans = (altSum == K) ? arr[curr] : -1;
        if(pick != -1)
            if(pick * arr[curr] <= lim) ans = max(ans, arr[curr] * pick);
        if(notPick != -1)
            ans = max(ans, notPick);
        return dp[curr][addOrSub][altSum] = ans;
    }
    int maxProduct(vector<int>& nums, int k, int limit) {
        arr = nums;
        arr.push_back(-1);
        n = nums.size();
        K = k;
        lim = limit;
        dp.assign(n, vector<unordered_map<int, int>>(2, unordered_map<int, int>()));
        return solve(0, 1, nums[0]);
    }
};