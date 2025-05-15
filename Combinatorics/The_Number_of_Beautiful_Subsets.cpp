#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
using namespace std;

int beautifulSubsets(vector<int> nums, int k) {
    int n = nums.size();
    int ans = 0;
    sort(nums.begin(), nums.end());
    for(int i = 1; i < (1 << n); i++) {
        vector<int> subset;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                subset.push_back(nums[j]);
            }
        }
        bool isBeautiful = true;
        for(auto& x : subset) {
            for(auto& y : subset) {
                if(x == y) continue;
                if(abs(x - y) == k) {
                    isBeautiful = false;
                    break;
                }
            }
            if(!isBeautiful) break;
        }
        ans += isBeautiful;
    }
    return ans;
}

int main() {
    cout << beautifulSubsets({6,3,9,2,8,3,6,4,9,1,5}, 2);
    return 0;
}