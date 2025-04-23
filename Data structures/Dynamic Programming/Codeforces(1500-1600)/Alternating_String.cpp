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

int t, n;
string s;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> s;
        if(n == 1) {
            cout << 1 << endl;
            continue;
        }
        if(n == 2) {
            cout << 0 << endl;
            continue;
        }
        if(n == 3) {
            cout << 1 << endl;
            continue;
        }
        vector<vector<int>> evenPrefix(n + 1, vector<int>(26));
        vector<vector<int>> oddPrefix(n + 1, vector<int>(26));
        for(int i = 1; i <= n; i++) {
            evenPrefix[i] = evenPrefix[i - 1];
            if(i & 1) evenPrefix[i][s[i - 1] - 'a'] = evenPrefix[i - 1][s[i - 1] - 'a'] + 1;
            oddPrefix[i] = oddPrefix[i - 1];
            if(!(i & 1)) oddPrefix[i][s[i - 1] - 'a'] = oddPrefix[i - 1][s[i - 1] - 'a'] + 1;
        }
        if(n & 1) {
            int numOps = n;
            for(int i = 1; i <= n; i++) {
                int maxEvenCharFreq = 0;
                int maxOddCharFreq = 0;
                for(int c = 0; c < 26; c++) {
                    int evenCount = 0;
                    int oddCount = 0;
                    int l = 1, r = i - 1;
                    if(l <= r) evenCount += evenPrefix[r][c] - evenPrefix[l - 1][c];
                    if(l <= r) oddCount += oddPrefix[r][c] - oddPrefix[l - 1][c];
                    l = i + 1, r = n;
                    if(l <= r) evenCount += oddPrefix[r][c] - oddPrefix[l - 1][c];
                    if(l <= r) oddCount += evenPrefix[r][c] - evenPrefix[l - 1][c];
                    maxEvenCharFreq = max(maxEvenCharFreq, evenCount);
                    maxOddCharFreq = max(maxOddCharFreq, oddCount);
                }
                numOps = min(numOps, n / 2 - maxEvenCharFreq + n / 2 - maxOddCharFreq + 1);
            }
            cout << numOps << endl;
        } else {
            int maxEvenCharFreq = 0;
            int maxOddCharFreq = 0;
            for(int c = 0; c < 26; c++) {
                int evenCount = 0;
                int oddCount = 0;
                int l = 1, r = n;
                evenCount += evenPrefix[r][c] - evenPrefix[l - 1][c];
                oddCount += oddPrefix[r][c] - oddPrefix[l - 1][c];
                maxEvenCharFreq = max(maxEvenCharFreq, evenCount);
                maxOddCharFreq = max(maxOddCharFreq, oddCount);
            }
            cout << n / 2 - maxEvenCharFreq + n / 2 - maxOddCharFreq << endl;
        }
    }
    return 0;
}