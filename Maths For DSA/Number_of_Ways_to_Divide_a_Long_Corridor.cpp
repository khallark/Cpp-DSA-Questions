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

long long numberOfWays(string s) {
    int n = s.length();
    int l = 0, r = n - 1;
    while(l < n && s[l] == 'P') l++;
    while(r >= 0 && s[r] == 'P') r--;
    string temp = "";
    int numS = 0;
    for(int i = l; i <= r; i++) {
        if(s[i] == 'S') numS++;
        temp += s[i];
    }
    if(temp.length() == 0) return 0;
    if(numS & 1) return 0;
    s = temp;
    vector<int> a;
    int i = 0;
    while(i < s.length()) {
        if(s[i] == 'S') {
            a.push_back(-1);
            if(i < s.length() - 1 && s[i + 1] == 'S') a.push_back(1);
            i++;
        } else {
            int cnt = 1;
            while(s[i] == 'P') {
                cnt++; i++;
            }
            a.push_back(cnt);
        }
    }
    long long ans = 1;
    numS = 0;
    const int mod = 1e9 + 7;
    for(int i = 0; i < a.size(); i++) {
        if(numS < 2) {
            if(a[i] == -1) numS++;
        } else {
            numS = 0;
            ans = (ans * a[i]);
        }
    }
    return ans;
}

int main() {
    cout << numberOfWays("SPPSSPSPPPSSPSPPSP");
    return 0;
}