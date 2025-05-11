#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
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

long long countPairs(vector<int>& nums, int k) { // O(n * d) [d being the number of divisors of k]
    unordered_map<long long, long long> gcdFreq;
    long long count = 0;
    for (int num : nums) {
        long long g = gcd(num, k);
        for (auto& [g2, freq] : gcdFreq) {
            if ((1LL * g * g2) % k == 0) {
                count = count + freq;
            }
        }
        gcdFreq[g]++;
    }
    return count;
}

// https://leetcode.com/problems/count-array-pairs-divisible-by-k/

int main() {
    vector<int> nums = {1,2,3,4,5}; int k = 2;
    cout << countPairs(nums, k);
    return 0;
}