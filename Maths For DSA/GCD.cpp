#include <iostream>
using namespace std;
int GCD(int x, int y) {
    if (x == 0) return y;
    if(y == 0) return x;
    while(x != y) {
        if(x > y)  x = x - y;
        if(y > x) y = y - x;
    }
    return x;
}
int GCD_better(int x, int y) {
    if (x == 0) {
        return y;
    }
    if (y == 0) {
        return x;
    }
    while(x != 0 && y != 0) {
        if (x > y) {
            x = x % y;
        }
        else {
            y = y % x;
        }
    }
    return x == 0 ? y : x;
}
int main() {
    int x = 23, y = 31;
    cout << GCD_better(x, y) << endl;
    cout << (-8 % 7) + 7 << endl;
    return 0;
}