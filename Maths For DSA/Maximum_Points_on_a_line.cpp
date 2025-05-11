#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iomanip>

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
using namespace std;

string to_stringWithPrecision(double value) {
    ostringstream out;
    out << fixed << setprecision(10) << value;
    return out.str();
}
int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    unordered_map<string, unordered_set<string>> m;
    unordered_map<string, unordered_set<string>> undefined;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(points[i][0] - points[j][0] != 0) {
                double slope;
                slope = double(points[i][1] - points[j][1]) /
                        double(points[i][0] - points[j][0]);
                string key = to_stringWithPrecision(points[i][0]) + ','
                            + to_stringWithPrecision(points[i][1]) + '-'
                            + to_stringWithPrecision(slope);
                m[key].insert({
                    to_stringWithPrecision(points[i][0]) + ',' + to_stringWithPrecision(points[i][1]),
                    to_stringWithPrecision(points[j][0]) + ',' + to_stringWithPrecision(points[j][1])
                });
            } else {
                string key = to_stringWithPrecision(points[i][0]) + ','
                            + to_stringWithPrecision(points[i][1]);
                undefined[key].insert({
                    to_stringWithPrecision(points[i][0]) + ',' + to_stringWithPrecision(points[i][1]),
                    to_stringWithPrecision(points[j][0]) + ',' + to_stringWithPrecision(points[j][1])
                });
            }
        }
    }
    int ans = 1;
    for(auto &i : m) {
        ans = max(ans, static_cast<int>(i.second.size()));
    }
    for(auto &i : undefined) {
        ans = max(ans, static_cast<int>(i.second.size()));
    }
    return ans;
}

int main() {
    vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout << maxPoints(points);
    return 0;
}