#include <iostream>
using namespace std;

int Nth_root(int x, int power) {
    double ans = x;
    double s = 0;
    double e = x;
    double mid = s + int(e - s) / 2;
    while(s <= e) {
        double num = 1;
        for(int i = 0; i < power && num < ans; i++) num *= mid;
        if(num == ans) return mid;
        else if(num < ans) s = mid + 1;
        else e = mid - 1;
        mid = s + int(e - s) / 2;
    }
    return min(s, e);
}

int main() {
    cout << Nth_root(64,5);
    return 0;
}