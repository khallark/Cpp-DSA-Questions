#include <iostream>
#include <vector>
using namespace std;
const int M=1e9+7;

pair<int, int> solve(string &exp, vector<vector<pair<int, int>>> &dp, int i, int j) {
    if(i + 1 == j) {
        if(exp[i] == 'T') return make_pair(1, 0);
        else return make_pair(0, 1);
    }
    if(dp[i][j] != make_pair(-1, -1)) return dp[i][j];

    pair<int, int> totalWays = {0, 0};
    for(int k = i + 1; k < j; k += 2) {
        pair<int, int> left = solve(exp, dp, i, k);
        pair<int, int> right = solve(exp, dp, k + 1, j);
        int Tways, Fways;
        if(exp[k] == '|') {
            Tways = ((left.first * 1LL * (right.first + 0LL + right.second)) % M + 0LL + (right.first * (left.first + 0LL + left.second)) % M - (left.first * 1LL * right.first) % M) % M;
            Fways = (left.second * 1LL * right.second) % M;
        }
        else if(exp[k] == '&') {
            Tways = (left.first * 1LL * right.first) % M;
            Fways = ((left.second * 1LL * (right.first + 0LL + right.second)) % M + 0LL + (right.second * (left.first + 0LL + left.second)) % M - (left.second * 1LL * right.second) % M) % M;
        }
        else if(exp[k] == '^') {
            Tways = ((left.first * 1LL * right.second) % M + 0LL + (left.second * 1LL * right.first) % M) % M;
            Fways = ((left.first * 1LL * right.first) % M + 0LL + (left.second * 1LL * right.second) % M) % M;
        }
        totalWays.first = (totalWays.first + 0LL + Tways) % M;
        totalWays.second = (totalWays.second + 0LL + Fways) % M;
    }
    
    return dp[i][j] = totalWays;
}
int evaluateExp1(string & exp) {
    vector<vector<pair<int, int>>> dp(exp.length() + 1, vector<pair<int, int>>(exp.length() + 1, {-1, -1}));
    return solve(exp, dp, 0, exp.length()).first;
}


int evaluateExp2(string & exp) {
    int n = exp.length();
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n + 1));

    for(int i = 0; i < n; i++) {
        if(exp[i] == 'T') dp[i][i + 1] = {1, 0};
        else dp[i][i + 1] = {0, 1};
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = i + 2; j <= n; j++) {
            pair<int, int> totalWays = {0, 0};
            for(int k = i + 1; k < j; k += 2) {
                pair<int, int> left = dp[i][k];
                pair<int, int> right = dp[k + 1][j];
                int Tways, Fways;
                if(exp[k] == '|') {
                    Tways = ((left.first * 1LL * (right.first + 0LL + right.second)) % M + 0LL + (right.first * (left.first + 0LL + left.second)) % M - (left.first * 1LL * right.first) % M) % M;
                    Fways = (left.second * 1LL * right.second) % M;
                }
                else if(exp[k] == '&') {
                    Tways = (left.first * 1LL * right.first) % M;
                    Fways = ((left.second * 1LL * (right.first + 0LL + right.second)) % M + 0LL + (right.second * (left.first + 0LL + left.second)) % M - (left.second * 1LL * right.second) % M) % M;
                }
                else if(exp[k] == '^') {
                    Tways = ((left.first * 1LL * right.second) % M + 0LL + (left.second * 1LL * right.first) % M) % M;
                    Fways = ((left.first * 1LL * right.first) % M + 0LL + (left.second * 1LL * right.second) % M) % M;
                }
                totalWays.first = (totalWays.first + 0LL + Tways) % M;
                totalWays.second = (totalWays.second + 0LL + Fways) % M;
            }
            
            dp[i][j] = totalWays;
        }
    }

    return dp[0][n].first;
}


int main() {
    string exp = "F|T^F";
    cout << evaluateExp1(exp) << endl;
    return 0;
}