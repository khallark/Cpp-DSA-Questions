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

int t, n, k, m;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k >> m;
        string s;
        cin >> s;
        vector<vector<char>> a;
        for(int i = 0; i < m;) {
            set<char> st;
            vector<char> temp_set;
            while(i < m && st.size() < k) {
                if(s[i] >= 'a' + k) {
                    i++;
                    continue;
                }
                if(st.find(s[i]) == st.end()) {
                    st.insert(s[i]);
                    temp_set.push_back(s[i]);
                }
                i++;
            }
            a.push_back(temp_set);
        }
        if(a.size() == n) {
            string str = "";
            for(int i = 0; i < n - 1; i++) {
                str += a[i].back();
            }
            if(a[n - 1].size() == k) cout << "YES" << endl;
            else {
                set<char> st;
                for(auto i : a[n - 1]) st.insert(i);
                char k = 'a';
                while(st.find(k) != st.end()) k++;
                cout << "NO" << endl << str << k << endl;
            }
        } else if(a.size() > n) {
            cout << "YES" << endl;
        } else {
            string str = "";
            int i;
            for(i = 0; i < a.size(); i++) {
                str += a[i].back();
            }
            for(; i < n; i++) str += 'a';
            cout << "NO" << endl << str << endl;
        }
    }
    return 0;
}