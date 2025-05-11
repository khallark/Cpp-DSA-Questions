#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <set>
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

bool canPartitionGrid(vector<vector<int>> grid) {
    int m = grid.size(), n = grid[0].size();
    vector<long long> prefixH(m + 1);
    vector<long long> prefixV(n + 1);
    for(int i = 0; i < m; i++) {
        prefixH[i + 1] = accumulate(grid[i].begin(), grid[i].end(), 0LL);
    }
    for(int i = 0; i < n; i++) {
        long long sum = 0;
        for(int j = 0; j < m; j++) {
            sum = sum + grid[j][i];
        }
        prefixV[i + 1] = sum;
    }
    unordered_map<long long, pair<set<int>, set<int>>> mp;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            mp[grid[i][j]].first.insert(i + 1);
            mp[grid[i][j]].second.insert(j + 1);
        }
    }
    

    for(int i = 1; i <= m; i++) {
        prefixH[i] += prefixH[i - 1];
    }
    for(int i = 1; i <= n; i++) {
        prefixV[i] += prefixV[i - 1];
    }

    if(m > 1) {
    for(int i = 1; i < m; i++) {
        if(prefixH[i] == prefixH[m] - prefixH[i]) return true;
        else {
            long long diff = llabs(prefixH[i] - (prefixH[m] - prefixH[i]));
            if(prefixH[i] < prefixH[m] - prefixH[i]) {
                if(i == m - 1) {
                    if(mp.count(diff) && mp[diff].first.find(m) != mp[diff].first.end()
                        && (grid[m - 1][0] == diff || grid[m - 1][n - 1] == diff)) return true;
                }
                else if(mp.count(diff) && mp[diff].first.upper_bound(i) != mp[diff].first.end())
                    return true;
            } else {
                if(i == 1) {
                    if(mp.count(diff) && mp[diff].first.find(1) != mp[diff].first.end()
                        && (grid[0][0] == diff || grid[0][n - 1] == diff)) return true;
                }
                else if(mp.count(diff)) {
                    auto it = mp[diff].first.upper_bound(i);
                    if(it != mp[diff].first.begin()) return true;
                }
            }
        }
    }
    }
    if(n > 1) {
    for(int i = 1; i < n; i++) {
        if(prefixV[i] == prefixV[n] - prefixV[i]) return true;
        else {
            long long diff = llabs(prefixV[i] - (prefixV[n] - prefixV[i]));
            if(prefixV[i] < prefixV[n] - prefixV[i]) {
                if(i == n - 1) {
                    if(mp.count(diff) && mp[diff].second.find(n) != mp[diff].second.end()
                        && (grid[0][n - 1] == diff || grid[m - 1][n - 1] == diff)) return true;
                }
                else if(mp.count(diff) && mp[diff].second.upper_bound(i) != mp[diff].second.end())
                    return true;
            } else {
                if(i == 1) {
                    if(mp.count(diff) && mp[diff].second.find(1) != mp[diff].second.end()
                        && (grid[0][0] == diff || grid[m - 1][0] == diff)) return true;
                }
                else if(mp.count(diff)) {
                    auto it = mp[diff].second.upper_bound(i);
                    if(it != mp[diff].second.begin()) return true;
                }
            }
        }
    }
    }

    return false;
}

int main() {
    cout << canPartitionGrid({{1,2,4},{2,3,5}});
    return 0;
}