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

int subsetXORSum(vector<int> nums) {
    int ans = 0;
    for(int i = 0; i < (1 << nums.size()); i++) {
        int Xor = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(i & (1 << j)) {
                Xor ^= nums[j];
            }
        }
        ans += Xor;
    }
    return ans;
}

int main() {
    cout << subsetXORSum({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
    return 0;
}