#include <iostream>
#include <vector>
using namespace std;
int primeRange(int x) {
    vector<int> prime(x + 1, true);
    prime[0] = prime[1] = false;
    int count = 0;
    for(int i = 2; i < x; i++) {
        if (prime[i]) {
            count++;
            for (int j = 2 * i; j < x; j += i)
            {
                prime[j] = false;
            }
        }
    }
    return count;
}
int main() {
    int x = 5000000;
    cout << primeRange(x) << endl;
    cout << 832 % 124 << endl;
    return 0;
}