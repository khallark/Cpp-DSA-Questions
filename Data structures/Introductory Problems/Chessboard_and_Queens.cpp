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



vector<vector<int>> fill(int i, int j, vector<vector<int>> chess) {
    REP(J, 0, 8) {
        if(chess[i][J] != 2) chess[i][J] = 1;
    }
    REP(I, 0, 8) {
        if(chess[I][j] != 2) chess[I][j] = 1;
    }
    REP(d, -7, 8) {
        int newRow = i + d, newCol = j + d;
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8 && chess[newRow][newCol] != 2) {
            chess[newRow][newCol] = 1;
        }
    }
    REP(d, -7, 8) {
        int newRow = i + d, newCol = j - d;
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8 && chess[newRow][newCol] != 2) {
            chess[newRow][newCol] = 1;
        }
    }
    return chess;
}

int f(int index, vector<vector<int>> chess) {
    if(index == 8) {
        return 1;
    }
    int ans = 0;
    REP(i, 0, 8) {
        if(chess[index][i] == 0) {
            vector<vector<int>> temp = fill(index, i, chess);
            ans += f(index + 1, temp);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> chess(8, vector<int>(8));
    REP(i, 0, 8) {
        REP(j, 0, 8) {
            char c;
            cin >> c;
            if(c == '*') chess[i][j] = 2;
        }
    }
    cout << f(0, chess);
    return 0;
}