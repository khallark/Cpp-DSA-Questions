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
    vector<int> spf;
    auto Sieve_of_Eratosthenes = [&](int n) {
        spf.assign(n + 1, 0);
        for(int i = 0; i <= 31; i++) {
            spf[i] = i;
        }
        for(int i = 2; i * i <= n; i++) {
            if(spf[i] == i) {
                for(int j = i * i; j <= n; j += i) {
                    if(spf[j] == j) spf[j] = i;
                }
            }
        }
    };
    Sieve_of_Eratosthenes(31);
    for(int i = 1; i < spf.size(); i++) {
        cout << i << " -> " << spf[i] << endl;
    }
    return 0;
}