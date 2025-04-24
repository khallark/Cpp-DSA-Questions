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

int main() {
    int q;
    cin >> q;
    vector<int> queries(q);
    int maxi = 0;
    for(auto &i : queries) {
        cin >> i;
        maxi = max(maxi, i);
    }

    vector<int> SPF(maxi + 1, 0);
    for(int i = 0; i <= maxi; i++) {
        SPF[i] = i;
    }
    SPF[0] = 1;
    for(int i = 2; i * i <= maxi; i++) {
        if(SPF[i] == i) {
            for(int j = i * i; j <= maxi; j += i) {
                if(SPF[j] == j) SPF[j] = i;
            }
        }
    }
    cout << endl;
    for(auto num : queries) {
        if(num <= 1) {
            cout << num << endl;
            continue;
        }
        int spf = SPF[num];
        vector<int> ans;
        /*
        for(int f = spf; f * f <= num; f++) { O(root n) ---<--+
             while(num % f == 0) {                            |
                 ans.push_back(f);                            |
                 num /= f;                                    |
             }                                                ^
        }                                                     |
        if(num > 1) ans.push_back(num);                       |
        */ while(num > 1) { // O(log n) better than ----->----+
            ans.push_back(SPF[num]);
            num /= SPF[num];
        }
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
6
12
1
3248644
1010101
2
10
*/