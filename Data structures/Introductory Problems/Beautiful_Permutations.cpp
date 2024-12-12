#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n == 2 || n == 3) {
        cout << "NO SOLUTION";
        return 0;
    }
    if(n == 4) {
        cout << "2 4 1 3";
        return 0;
    }
    int even = n & 1 ? n - 1 : n;
    int odd = n & 1 ? n : n - 1;
    for(int i = even; i > 0; i -= 2) {
        cout << i << " ";
    }
    for(int i = odd; i > 0; i -= 2) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}