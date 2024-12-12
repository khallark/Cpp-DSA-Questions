#include <iostream>
#include <vector>
#include <matrix.h>
using namespace std;
vector<int> divisibleSet(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> dp(n);
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        int maxi = INT_MIN;
        
        for(int j = 0; j < i; j++)
            if((arr[i] != 0 && arr[j] % arr[i] == 0)|| 
               (arr[j] != 0 && arr[i] % arr[j] == 0))
                maxi = max(maxi, dp[j] + 1);

        dp[i] = maxi == INT_MIN ? 1 : maxi;
    }
    int ans = INT_MIN, ind, prev;
    for(int i = 0; i < n; i++) if(ans < dp[i]) ind = i, ans = dp[i];
    prev = arr[ind];
    vector<int> ar(ans);
    ar[ans-- - 1] = arr[ind];

    for(int i = ind - 1; i >= 0 && ans >= 1; i--)
        if(dp[i] == ans && ((arr[i] != 0 && prev % arr[i] == 0)|| 
               (prev != 0 && arr[i] % prev == 0)))
            ar[ans-- - 1] = arr[i], prev = arr[i];

    return ar;
}
int main() {
    vector<int> arr = {16, 1, 1, 18, 24};
    cout << divisibleSet(arr);
    return 0;
}