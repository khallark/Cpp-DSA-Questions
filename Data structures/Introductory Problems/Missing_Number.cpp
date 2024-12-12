#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll totalSum = n;
    ll actualSum = 0;
    for(int i = 1; i < n; i++) {
        totalSum += i;
        ll x;
        cin >> x;
        actualSum += x;
    }
    cout << totalSum - actualSum << endl;
    return 0;
}