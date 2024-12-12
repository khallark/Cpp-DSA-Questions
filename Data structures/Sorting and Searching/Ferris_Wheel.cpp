#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> children(n);
    for(auto& i : children) cin >> i;
    sort(children.begin(), children.end());

    int count = 0;
    int left = 0, right = n - 1;
    while (left <= right) {
        if (children[left] + children[right] <= x) {
            left++;  // Pair the lightest and heaviest
        }
        right--;  // Group formed, move to the next heaviest
        count++;
    }

    cout << count << endl;
    return 0;
}