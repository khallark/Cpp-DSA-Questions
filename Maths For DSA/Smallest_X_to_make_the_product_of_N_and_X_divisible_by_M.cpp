#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
#include <numeric>

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
using namespace std;

int smallestX_version1(int n, int k) { // Highly un-optimized
    vector<int> prime_factors_of_n;
    vector<int> prime_factors_of_k;
    function<void(int, vector<int>&)> primeFactors = [&](int num, vector<int> &ans) {
        if(num == 1) return;
        for(ll i = 2; i * i <= num; i++) {
            if(num % i == 0) {
                while(num % i == 0) {
                    ans.push_back(i);
                    num /= i;
                }
            }
        }
        if(num != 1) ans.push_back(num);
    };
    primeFactors(n, prime_factors_of_n);
    primeFactors(k, prime_factors_of_k);

    vector<int> removedFromK(prime_factors_of_k.size(), 0);
    
    int i = 0, j = 0;
    while(i < prime_factors_of_n.size() && j < prime_factors_of_k.size()) {
        if(prime_factors_of_n[i] == prime_factors_of_k[j]) {
            removedFromK[j] = 1;
            i++, j++;
        } else if(prime_factors_of_n[i] < prime_factors_of_k[j]) {
            i++;
        } else {
            j++;
        }
    }
    int ans = 1;
    for(int i = 0; i < prime_factors_of_k.size(); i++) {
        if(!removedFromK[i]) ans *= prime_factors_of_k[i];
    }
    return ans;
}

int smallestX_version2(int n, int k) { // Highly Optimized
    int GCD = gcd(n, k);
    return k / GCD;
}

int main() {
    int N = 450;
    int K = 756;
    cout << smallestX_version1(N, K);
    cout << smallestX_version2(N, K);
    return 0;
}