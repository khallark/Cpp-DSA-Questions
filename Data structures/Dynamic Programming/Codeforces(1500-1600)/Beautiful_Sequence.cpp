/*
Let's call an integer sequence beautiful if the following conditions hold:

its length is at least 3
;
for every element except the first one, there is an element to the left less than it;
for every element except the last one, there is an element to the right larger than it;
For example, [1,4,2,4,7] and [1,2,4,8] are beautiful, but [1,2], [2,2,4], and [1,3,5,3] are not.

Recall that a subsequence is a sequence that can be obtained from another sequence by removing some elements without changing the order
of the remaining elements.

You are given an integer array a of size n, where every element is from 1 to 3.
Your task is to calculate the number of beautiful subsequences of the array a.
Since the answer might be large, print it modulo 998244353.

Input
The first line contains a single integer t (1≤t≤10^4) — the number of test cases.
The first line of each test case contains a single integer n (3≤n≤2⋅10^5).

The second line contains n integers a1,a2,…,an (1≤ai≤3).

Additional constraint on the input: the sum of n over all test cases doesn't exceed 2⋅105.

Output
For each test case, print a single integer — the number of beautiful subsequences of the array a, taken modulo 998244353.
*/

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

ll t, n;
const int MOD = 998244353;

long long power(long long a, long long b, long long MOD = LLONG_MAX) {
    long long result = 1;
    if (MOD != LLONG_MAX) a %= MOD;

    while (b > 0) {
        if (b & 1) {
            result = (MOD == LLONG_MAX) ? (result * a) : (result * a) % MOD;
        }
        a = (MOD == LLONG_MAX) ? (a * a) : (a * a) % MOD;
        b >>= 1;
    }
    
    return result;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        vll a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        vll p(n + 1);
        p[0] = 0;
        for(int i = 0; i < n; i++) {
            p[i + 1] = p[i] + (a[i] == 2);
        }

        ll p1 = 0;
        while(p1 < n && a[p1] != 1) p1++;
        if(p1 == n) {
            cout << 0 << endl;
            continue;
        }

        ll ans = 0;
        ll sum = 0;
        ll cnt = 0;
        for(int i = p1; i < n; i++) {
            if(a[i] == 3) {
                sum = (sum + power(2, p[i + 1], MOD)) % MOD;
                cnt++;
            }
        }
        for(int i = p1; i < n; i++) {
            if(a[i] == 1) {
                ans = (ans + sum * power(power(2, p[i], MOD), MOD - 2, MOD) % MOD - cnt + MOD) % MOD;
            } else if(a[i] == 3) {
                sum = (sum - power(2, p[i + 1], MOD) + MOD) % MOD;
                cnt--;
            }
        }


        cout << ans << endl;
    }
    return 0;
}