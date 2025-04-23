#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

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
    ll n;
    cin >> n;
    set<ll> s;
    for(ll i = 1; i * i <= n; i++) 
        if(n % i == 0) s.insert({i, n / i});
        
    for(auto i : s)
        cout << i << " ";
    return 0;
}