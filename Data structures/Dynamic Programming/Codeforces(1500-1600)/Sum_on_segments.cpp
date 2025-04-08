#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
using namespace std;

int t, n;
vll a;

vll MaxMinSubarraySum(int l, int r) {
    ll maxSoFar = a[l];
    ll minSoFar = a[l];
    ll currentMax = a[l];
    ll currentMin = a[l];
    for(int i = l + 1; i <= r; i++) {
        currentMax = max(a[i], currentMax + a[i]);
        currentMin = min(a[i], currentMin + a[i]);
        maxSoFar = max(currentMax, maxSoFar);
        minSoFar = min(currentMin, minSoFar);
    }
    return {minSoFar, maxSoFar};
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        a = vll(n);
        ll x = -1;
        int index = -1;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] != 1 && a[i] != -1) x = a[i], index = i;
        }
        if(x != -1) {
            set<int> s;
            s.insert(0);
            if(index > 0) {
                vll left = MaxMinSubarraySum(0, index - 1);
                for(int i = left[0]; i <= left[1]; i++) s.insert(i);
            }
            if(index < n - 1) {
                vll right = MaxMinSubarraySum(index + 1, n - 1);
                for(int i = right[0]; i <= right[1]; i++) s.insert(i);
            }
            ll  minP = 0, maxP = 0, curP = 0;
            for(int i = index + 1; i < n; i++) {
                curP += a[i];
                minP = min(minP, curP);
                maxP = max(maxP, curP);
            }
            ll minS = 0, maxS = 0, curS = 0;
            for(int i = index - 1; i >= 0; i--) {
                curS += a[i];
                minS = min(minS, curS);
                maxS = max(maxS, curS);
            }
            for(int i = minP + minS + x; i <= maxP + maxS + x; i++) s.insert(i);
            cout << s.size() << endl;
            for(auto i : s) cout << i << ' ';
            cout << endl << endl;
        } else {
            vll all = MaxMinSubarraySum(0, n - 1);
            set<int> s;
            s.insert(0);
            for(int i = all[0]; i <= all[1]; i++) s.insert(i);
            cout << s.size() << endl;
            for(auto i : s) cout << i << ' ';
            cout << endl << endl;
        }
    }
    return 0;
}