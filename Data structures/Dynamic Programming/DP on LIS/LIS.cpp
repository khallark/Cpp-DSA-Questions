#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int longestIncreasingSubsequence1(int arr[], int n) {
    vector<int> sorted_arr(arr, arr + n);
    sort(sorted_arr.begin(), sorted_arr.end());
    vector<int> temp;
    for(int i = 0; i < sorted_arr.size(); i++) {
        if(i == 0 || sorted_arr[i - 1] != sorted_arr[i]) temp.push_back(sorted_arr[i]); 
    }
    vector<int> dp(n + 1);
    int prevVal;
    for(int i = 1; i <= n; i++) {
        prevVal = dp[0];
        for(int j = 1; j <= n; j++) {
            int tmp = prevVal;
            prevVal = dp[j];
            if(temp[i - 1] == arr[j - 1]) {
                dp[j] = tmp + 1;
            }
            else {
                dp[j] = max(dp[j], dp[j - 1]);
            }
        }
    }
    return dp[n];
}





int longestIncreasingSubsequence2(int arr[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j <= n; j++) {
            int len = dp[i + 1][j];
            if(j == 0 || arr[i] > arr[j - 1])
                len = max(len, dp[i + 1][i + 1] + 1);
            dp[i][j] = len;
        }
    }
    return dp[0][0];
}





int longestIncreasingSubsequence3(int arr[], int n)
{
    vector<int> dp(n);
    dp[0] = 1;
    int ans = INT_MIN;
    for(int i = 1; i < n; i++) {
        int maxi = INT_MIN;
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i])
                maxi = max(maxi, dp[j] + 1);
        }
        dp[i] = maxi == INT_MIN ? 1 : maxi;
        ans = max(ans, dp[i]);
    }
    for(auto i : dp) {
        cout << i << " ";
    }
    cout << endl;
    return ans;
}





void binary_search(vector<int> &arr, int target) {
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    while(s <= e) {
        if(arr[mid] == target) {
            s = mid, e = mid;
            break;
        }
        else if(arr[mid] < target) s = mid + 1;
        else e = mid - 1;

        mid = s + (e - s) / 2;
    }
    if((e >= 0 && e < arr.size()) && arr[e] > target) arr[e] = target;
    else if((s >= 0 && s < arr.size()) && arr[s] > target) arr[s] = target;
}   
int longestIncreasingSubsequence4(int arr[], int n)
{
    vector<int> array;
    array.push_back(arr[0]);
    for(int i = 1; i < n; i++) {
        if(arr[i] > array.back()) array.push_back(arr[i]);
        else binary_search(array, arr[i]);
        for(auto i : array) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return array.size();
}





int main() {
    int arr[] = {1, 3, 5, 4, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << longestIncreasingSubsequence3(arr, size);
    return 0;
}