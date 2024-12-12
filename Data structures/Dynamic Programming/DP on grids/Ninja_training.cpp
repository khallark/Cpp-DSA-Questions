#include <iostream>
#include <vector>
using namespace std;

// Recursion with DP (Memoization)
int solve(int n, int index, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if(n == 0) {
        return dp[n][index] = points[n][index];
    }
    if(dp[n][index] != -1) {
        return dp[n][index];
    }

    int maxi;

    switch(index) {
    case 0:
        maxi = max(solve(n - 1, 1, points, dp), solve(n - 1, 2, points, dp));
        break;
    case 1:
        maxi = max(solve(n - 1, 0, points, dp), solve(n - 1, 2, points, dp));
        break;
    case 2:
        maxi = max(solve(n - 1, 0, points, dp), solve(n - 1, 1, points, dp));
        break;
    }

    return dp[n][index] = points[n][index] + maxi;
}
int ninjaTraining1(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(3, -1));
    return max(solve(n - 1, 0, points, dp), max(solve(n - 1, 1, points, dp), solve(n - 1, 2, points, dp)));
}


// DP with iteration (Tabulation)
int ninjaTraining2(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(3, -1));
    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];

    for(int i = 1; i < n; i++) {
        int maxi;
        for(int index = 0; index < 3; index++) {
            switch(index) {
            case 0:
                maxi = max(dp[i - 1][1], dp[i - 1][2]);
                break;
            case 1:
                maxi = max(dp[i - 1][0], dp[i - 1][2]);
                break;
            case 2:
                maxi = max(dp[i - 1][0], dp[i - 1][1]);
                break;
            }

            dp[i][index] = points[i][index] + maxi;
        }
    }
    return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}


// DP with Space Optimization
int ninjaTraining3(int n, vector<vector<int>> &points) {
    
    int a = points[0][0];
    int b = points[0][1];
    int c = points[0][2];

    for(int i = 1; i < n; i++) {
        int maxi;
        int temp0 = a, temp1 = b, temp2 = c;
        for(int index = 0; index < 3; index++) {
            switch(index) {
            case 0:
                maxi = max(temp1, temp2);
                break;
            case 1:
                maxi = max(temp0, temp2);
                break;
            case 2:
                maxi = max(temp0, temp1);
                break;
            }
            
            if(index == 0) {
                a = points[i][index] + maxi;
            }
            else if(index == 1) {
                b = points[i][index] + maxi;
            }
            else if(index == 2) {
                c = points[i][index] + maxi;
            }
        }
    }
    return max(a, max(b, c));
}

int main() {
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };
    int n = points.size();
    cout << ninjaTraining3(n, points);
    return 0;
}