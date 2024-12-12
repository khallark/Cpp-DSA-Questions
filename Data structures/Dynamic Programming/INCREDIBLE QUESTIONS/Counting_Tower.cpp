#include <iostream>
#include <vector>
using namespace std;
const int M = 1000000007;
int main() {
    int t;
    int n;
    cin >> t;
    int two_blocks, horizontal_bar;
    while(t--) {
        cin >> n;
        two_blocks = 1, horizontal_bar = 1;
        for(int i = 0; i < n - 1; i++) {
            int t1 = ((4LL * two_blocks) + (horizontal_bar) + 0LL) % M;
            int t2 = ((two_blocks) + (2LL * horizontal_bar) + 0LL) % M;
            two_blocks = t1, horizontal_bar = t2;
        }
        cout << (two_blocks + horizontal_bar) % M << endl;
    }
    return 0;
}