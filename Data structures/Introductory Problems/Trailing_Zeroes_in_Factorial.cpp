#include <iostream>
#define ll long long
#define pii pair<int, int>
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll num_zeroes = 0;
    ll factor_of_five = 5;
    while(factor_of_five <= n) {
        num_zeroes += n / factor_of_five;
        factor_of_five *= 5LL;
    }
    cout << num_zeroes << endl;
    return 0;
}