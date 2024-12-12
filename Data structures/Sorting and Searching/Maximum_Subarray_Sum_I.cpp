#include <iostream>
#include <vector>
#include <climits>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(auto& i : arr) cin >> i;
    int i = 0, j = 0;
    ll sum = 0;
    ll maxSum = LLONG_MIN;
    while(j < n) {
        sum += arr[j];
        maxSum = max(maxSum, sum);
        while(sum < 0) {
            maxSum = max(maxSum, sum);
            sum -= arr[i++];
        }
        j++;
    }
    cout << maxSum << endl;
    return 0;
}