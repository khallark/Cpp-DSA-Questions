#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> nums(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
        nums[i] += nums[i - 1]; // prefix sum
    }
    map<ll, ll> m;
    m[0] = 1;
    ll count = 0;
    for(int i = 1; i <= n; i++) {
        count += m[nums[i] - x];
        m[nums[i]]++;
    }
    cout << count << endl;
    return 0;
}