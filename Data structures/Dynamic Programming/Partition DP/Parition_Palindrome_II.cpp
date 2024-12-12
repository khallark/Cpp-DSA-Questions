#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int isPalindrome(string str, int i, int j) {
    int left = i, right = j;
    while(left < right) {
        if(str[left++] != str[right--]) return false;
    }
    return true;
}
int palindromePartitioning(string str) {
    int n = str.length();
    vector<int> dp(n + 1);
    dp[n] = -1;

    for(int i = n - 1; i >= 0; i--) {
        int mini = INT_MAX;
        for(int j = i; j < n; j++) {
            if(isPalindrome(str, i, j)) {
                mini = min(mini, 1 + dp[j + 1]);
            }
        }
        dp[i] = mini;
    }

    return dp[0];
}
int main() {
    string a = "";
    cout << palindromePartitioning(a) << endl;
    return 0;
}