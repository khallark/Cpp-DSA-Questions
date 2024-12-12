#include <iostream>
using namespace std;

int mySqrt(int x) {
    double sqr = x;
    double s = 0;
    double e = x;
    double mid = s + int(e - s) / 2;
    while(s <= e) {
        if(mid * mid == sqr) return mid;
        else if(mid * mid < sqr) s = mid + 1;
        else e = mid - 1;
        mid = s + int(e - s) / 2;
    }
    return min(s, e);
}

int main() {
    cout << mySqrt(100000);
    return 0;
}