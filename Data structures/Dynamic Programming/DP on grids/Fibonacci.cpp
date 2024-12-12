#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int fibonacci(int n, vector<int> &dp, int &count) {
    count++;

    if(n <= 1) {
        return n;
    }

    int a, b;

    if(dp[n - 1] != -1) a = dp[n - 1];
    else a = dp[n - 1] = fibonacci(n - 1, dp, count);

    if(dp[n - 2] != -1) b = dp[n - 2];
    else b = dp[n - 2] = fibonacci(n - 2, dp, count);

    return a + b;
}

    // if(dp[n] != -1) return dp[n];
    // return dp[n] = fibonacci(n - 1, dp, count) + fibonacci(n - 2, dp, count);


int fibonacci(int n, int &count) {
    count++;

    if(n <= 1) {
        return n;
    }

    return fibonacci(n - 1, count) + fibonacci(n - 2, count);
}

int fibonacci1(int n, int &count) {
    vector<int>dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        count++;
    }
    return dp[n];
}
int fibonacci2(int n, int &count) {
    int a = 0;
    int b = 1;
    for(int i = 2; i <= n; i++) {
        int temp = b;
        b = a + b;
        a = temp;
        count++;
    }
    return b;
}

int main() {
    int n = 24;

    // Normal Recusion.
    int count = 0;
    int val = fibonacci(n, count);
    cout << "Normal      Recursion          : " << val << ", " << count << endl;

    // Recusion with DP
    vector<int> dp(n + 1, -1);
    count = 0;
    val = fibonacci(n, dp, count);
    cout << "Recursion     with     DP      : " << val << ", " << count << endl;

    // DP with tabulation.
    count = 0;
    val = fibonacci1(n, count);
    cout << "DP       with     tabulation   : " << val << ", " << count << endl;

    // Fibonacci with brain [o(1) SC].
    count = 0;
    val = fibonacci2(n, count);
    cout << "Fibonacci with brain [o(1) SC] : " << val << ", " << count << endl;
    return 0;
}