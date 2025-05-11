#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
using namespace std;

int minKBitFlips(vector<int> A, int K) {
    int res = 0;
    queue<int> flips;
    for (auto i = 0; i < A.size(); ++i) {
        if (A[i] != (flips.size() % 2 ? 0 : 1)) { // here we are basically checking if A[i] == 1 or not, taking into account the flips, mean for odd flips, 1 will actually mean 0, but for even, 1 will mean 1 only
        ++res;
        flips.push(i + K - 1);
        }
        if (!flips.empty() && flips.front() <= i) flips.pop();
    }
    return flips.empty() ? res : -1;
}

int main() {
    cout << minKBitFlips(vector<int>{0,0,0,1,0,1,1,0}, 3);
    return 0;
}