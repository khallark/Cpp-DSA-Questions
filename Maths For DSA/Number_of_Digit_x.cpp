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

int countDigitX(int n, int x) {
    if (n < 1) return 0;

    int count = 0;
    long long i = 1;

    while (i <= n) {
        int high = n / (i * 10);
        int cur = (n / i) % 10;
        int low = n % i;

        if (x != 0) {
            if (cur > x) {
                count += (high + 1) * i;
            } else if (cur == x) {
                count += high * i + (low + 1);
            } else {
                count += high * i;
            }
        } else {
            if (high == 0) break; // leading 0s are not valid
            if (cur == 0) {
                count += (high - 1) * i + (low + 1);
            } else {
                count += high * i;
            }
        }

        i *= 10;
    }

    return count;
}

// https://leetcode.com/problems/number-of-digit-one/
int main() {
    cout << countDigitX(5389, 1);
    return 0;
}