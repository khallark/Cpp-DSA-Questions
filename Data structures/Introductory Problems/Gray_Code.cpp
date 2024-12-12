#include <iostream>
#include <bitset>
#include <cmath>
#define ll long long
#define pii pair<int, int>
using namespace std;

int binary_to_gray(int n) {
    return n ^ (n >> 1);
}

int main() {
    int n;
    cin >> n;
    bitset<16> b;
    int num = pow(2, n);
    for(int i = 0; i < num; i++) {
        b = binary_to_gray(i);
        cout << b.to_string().substr(16 - n) << endl;
    }
    return 0;
}