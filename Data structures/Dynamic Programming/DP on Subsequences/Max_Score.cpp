#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define L long long

/*
You are given an integer array a of size 4 and another integer array b of size at least 4.
You need to choose 4 indices i0, i1, i2, and i3 from the array b such that i0 < i1 < i2 < i3.
Your score will be equal to the value a[0] * b[i0] + a[1] * b[i1] + a[2] * b[i2] + a[3] * b[i3].
Return the maximum score you can achieve.
Example :
    Input: a = [3,2,5,6], b = [2,-6,4,-5,-3,2,-7]
    Output: 26
    Explanation: We can choose the indices 0, 1, 2, and 5. The score will be 3 * 2 + 2 * (-6) + 5 * 4 + 6 * 2 = 26.
*/

L maxScore(vector<int>& a, vector<int>& b) {
    int n = b.size();
    vector<vector<L>> dp(4, vector<L>(n, INT_MIN));
    for(int i = 0; i < n; i++) dp[3][i] = (L)a[3] * (L)b[i];
    for(int i = 2; i >= 0; i--) {
        vector<L> maxVal(n, INT_MIN);
        L maxi = dp[i + 1][n - 1];
        for(int k = n - 1; k >= 0; k--) {
            maxi = max(maxi, dp[i + 1][k]);
            maxVal[k] = maxi;
        }
        for(int j = 0; j < n - 1; j++) {
            dp[i][j] = (L)a[i] * (L)b[j] + maxVal[j + 1];
        }
    }
    L result = INT_MIN;
    for (int i = 0; i < n; i++) {
        result = max(result, dp[0][i]);
    }
    return result;
}

int main() {
    vector<int> a = {3,2,5,6}, b = {2,-6,4,-5,-3,2,-7};
    cout << maxScore(a, b);
    return 0;
}