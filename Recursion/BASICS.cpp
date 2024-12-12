#include <iostream>
using namespace std;
int fact(int n) {
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}
int expo(int n) {
    if (n == 0) {
        return 1;
    }
    return 2 * expo(n - 1);
}
void reverse_print(int n) {
    if (n == 1) {
        cout << n << " ";
        return;
    }
    reverse_print(n - 1);
    cout << n << " ";
}
int main() {
    cout << fact(5) << endl;
    cout << expo(6) << endl;
    reverse_print(10);
    return 0;
}