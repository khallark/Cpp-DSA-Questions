#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool customComparator(string a, string b) {
    return a.length() < b.length();
}
int longestStrChain(vector<string> &arr){
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        sort(arr[i].begin(), arr[i].end());
    }

    sort(arr.begin(), arr.end(), customComparator);

    vector<int> dp(n, 1);
    dp[0] = 1;
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j].length() != arr[i].length() - 1) continue;

            int currLen = arr[i].length();
            int prevLen = currLen - 1;

            int a = 0, b = 0;
            while(a < prevLen && b < currLen) {
                if(arr[j][a] == arr[i][b]) a++;
                b++;
            }
            
            if(a == prevLen) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }

    return ans;
}
int main() {
    vector<string> words = {"exxo", "f", "kjkl", "xo", "xxo", "x"};
    cout << longestStrChain(words);
    return 0;
}
