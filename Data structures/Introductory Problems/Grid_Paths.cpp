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
#define Vin(i, x, y) for(auto& i : v)
#define Vout(i, x, y) for(auto i : v)
using namespace std;

int dirs[26] = {0};
int row[] = {0, -1, 0, 1};
int col[] = {-1, 0, 1, 0};
string s;
vector<vi> visited(9, vi(9));

int f(int index, int i, int j) {
    if(visited[i - 1][j] && visited[i + 1][j] && !visited[i][j - 1] && !visited[i][j + 1]
                                            or
    !visited[i - 1][j] && !visited[i + 1][j] && visited[i][j - 1] && visited[i][j + 1]) {
        return 0;
    }

    if(i == 7 && j == 1) {
        return index == 48 ? 1 : 0;
    }
    if(index == 48) return 0;

    int ans = 0;
    visited[i][j] = 1;

    if(s[index] == '?') {
        REP(k, 0, 4) {
            int I = i + row[k], J = j + col[k];
            if(!visited[I][J]) {
                ans += f(index + 1, I, J);
            }
        }
    } else {
        int k = dirs[s[index] - 'A'];
        int I = i + row[k], J = j + col[k];
        if(!visited[I][J]) {
            ans += f(index + 1, I, J);
        }
    }

    visited[i][j] = 0;

    return ans;
}

int main() {
    dirs['L' - 'A'] = 0;
    dirs['U' - 'A'] = 1;
    dirs['R' - 'A'] = 2;
    dirs['D' - 'A'] = 3;
    REP(i, 0, 9) {
        visited[0][i] = visited[i][0] = visited[8][i] = visited[i][8] = true;
    }
    cin >> s;
    cout << f(0, 1, 1);
    return 0;
}