#include <iostream>
#include <vector>
using namespace std;

/*

Your task is to count the number of ways numbers 1,2,.....,n
can be divided into two sets of equal sum.

For example, if n=7, there are four solutions:
- {1,3,4,6} and {2,5,7}
- {1,2,5,6} and {3,4,7}
- {1,2,4,7} and {3,5,6}
- {1,6,7} and {2,3,4,5}
--> 4 ways

*/

const int M = 1e9 + 7;
int twoSets(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) sum += i;
    if(sum & 1) return 0;
    int k = sum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    for(int i = 1; i <= n; i++) dp[i][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            int notPick = dp[i - 1][j];
            int pick = 0;
            if(j - i >= 0) {
                pick = dp[i - 1][j - i];
            }
            dp[i][j] = (pick + notPick) % M;
        }
    }
    return (dp[n][k] * 500000004LL) % M;
}

int main() {
    int n = 100;
    cout << twoSets(n) << endl;
    return 0;
}