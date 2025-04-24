#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
using namespace std;

int main() {
    vector<bool> isPrime;
    auto Sieve_of_Eratosthenes = [&](int n) {
        isPrime.assign(n + 1, true);
        isPrime[1] = false;
        for(int i = 2; i * i <= n; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    };
    Sieve_of_Eratosthenes(31);
    for(int i = 1; i < isPrime.size(); i++) {
        cout << i << " -> " << isPrime[i] << endl;
    }
    return 0;
}