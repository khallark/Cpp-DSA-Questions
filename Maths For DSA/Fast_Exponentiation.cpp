#include <iostream>
using namespace std;
long double fast_expo(long double x, int n) {
    long double res = 1;
    while(n > 0) {
        if(n&1) res = res * x;
        x = x * x;
        n = n>>1;
    }
    return res;
}
int main() {
    long double x = 123.232;
    int n = 20;
    cout << "O(log n) pow function --> " << fixed << fast_expo(x, n) << endl;
    return 0;
}