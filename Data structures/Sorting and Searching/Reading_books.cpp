#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> bookTime(n);
    ll totalTime = 0;
    for(auto& i : bookTime) {
        cin >> i;
        totalTime += i;
    }
    ll maxTime = *max_element(bookTime.begin(), bookTime.end());
    cout << max(totalTime, 2 * maxTime) << endl;
    return 0;
}
