#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    while(n != 1) {
        cout << n << " ";
        if(n & 1) n = 3LL * n + 1LL;
        else n /= 2LL;
    }
    cout << 1 << endl;
    return 0;
}