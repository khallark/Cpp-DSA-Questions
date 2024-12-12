#include <iostream>
using namespace std;
double powerof(double x, int y) {
    double res = 1;
    if(y == 0) return res;
    if(y&1) res = res * x;
    return res * powerof(x * x, y>>1);
}
int main() {
    double x;
    int y;
    cout << "Enter x --> ";
    cin >> x;
    cout << "Enter y --> ";
    cin >> y;
    cout << "The value of (x^y) = " << powerof(x, y) << endl;
    return 0;
}