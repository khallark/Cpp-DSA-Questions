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

int t, prg, tst;

int main() {
    cin >> t;
    while(t--) {
        cin >> prg >> tst;
        int n = prg + tst + 1;
        vector<pi> skills(n + 1);
        for(int i = 1; i <= n; i++) cin >> skills[i].first;
        for(int i = 1; i <= n; i++) cin >> skills[i].second;
        vector<int> jobs(n + 1);
        int subOptimalIndex = n + 1;
        int subOptimalJob = -1;
        for(int i = 1; i <= n; i++) {
            if(!prg || !tst) {
                if(prg) {
                    if(skills[i].first > skills[i].second)
                        jobs[i] = skills[i].first;
                    else {
                        if(subOptimalIndex == n + 1) subOptimalIndex = i, subOptimalJob = 0;
                        else jobs[i] = skills[i].first;
                    }
                } else {
                    if(skills[i].second > skills[i].first)
                        jobs[i] = skills[i].second;
                    else {
                        if(subOptimalIndex == n + 1) subOptimalIndex = i, subOptimalJob = 1;
                        else jobs[i] = skills[i].second;
                    }
                }
                continue;
            }
            if(skills[i].first > skills[i].second) {
                prg--;
                jobs[i] = skills[i].first;
            } else {
                tst--;
                jobs[i] = skills[i].second;
            }
        }
        vector<int> subOptimal(n + 1);
        vector<int> optimal(n + 1);
        for(int i = 1; i <= n; i++) {
            subOptimal[i] = (i == subOptimalIndex ?
                min(skills[subOptimalIndex].first, skills[subOptimalIndex].second)
                :
                jobs[i]
            ) + subOptimal[i - 1];
            optimal[i] = (i == subOptimalIndex ?
                max(skills[subOptimalIndex].first, skills[subOptimalIndex].second)
                :
                jobs[i]
            ) + optimal[i - 1];
        }
        for(int i = 1; i <= n; i++) {
            int ans = 0;
            if(i == subOptimalIndex) {
                ans = subOptimal[n] - min(skills[i].first, skills[i].second);
            } if(i < subOptimalIndex) {
                if(skills[i].first > skills[i].second) {
                    ans = (subOptimalJob == 0) ?
                    (subOptimal[i - 1]) + (subOptimal[n] - subOptimal[i]) :
                    (optimal[i - 1]) + (optimal[n] - optimal[i]);
                } else {
                    ans = (subOptimalJob == 1) ?
                    (subOptimal[i - 1]) + (subOptimal[n] - subOptimal[i]) :
                    (optimal[i - 1]) + (optimal[n] - optimal[i]);
                }
            } else {
                ans = subOptimal[i - 1] + (subOptimal[n] - subOptimal[i]);
            }
            cout << ans << ' ';
        }
        cout << endl << endl;
    }
    return 0;
}