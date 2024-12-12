#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(auto& i : arr) cin >> i;
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] < arr[i - 1]) {
            ans += arr[i - 1] - arr[i];
            arr[i] += arr[i - 1] - arr[i];
        }
    }
    cout << ans << endl;
    return 0;
}