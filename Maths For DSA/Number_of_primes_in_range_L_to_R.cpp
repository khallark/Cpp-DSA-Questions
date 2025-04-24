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

vector<int> Prefix_Sieve_of_Eratosthenes(int n) {
    vector<int>isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i * i <= n; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    return isPrime;
}

int main() {
    int q, l, r;
    cin >> q;
    vector<pair<int, int>> queries(q);
    int maxR = INT_MIN;
    for(auto& i : queries) {
        cin >> l >> r;
        maxR = max(maxR, r);
        i = make_pair(l, r);
    }
    vector<int> primes = Prefix_Sieve_of_Eratosthenes(maxR);
    vector<int> prfx(primes.size(), 0);
    for(int i = 1; i < primes.size(); i++) {
        prfx[i] = primes[i] + prfx[i - 1];
    }
    for(auto i : queries) {
        if(primes[i.first]) cout << prfx[i.second] - (prfx[i.first - 1]) << endl;
        else cout << prfx[i.second] - (prfx[i.first]) << endl;
    }
    return 0;
}