#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;
long long int Coin_Combs_I(long long int n, long long int x, vector<long long int> &c) {
    vector<long long int> ways(x, 0);
    long long int sum_ = 0;
    for(auto i : c) {
        long long int var;
        if(i == 0 + 1) var = 1;
        else if(i > 0 + 1) var = 0;
        sum_ += var;
    }
    ways[0] = sum_ % MOD;
    for(int i = 1; i < x; i++) {
        long long int sum_ = 0;
        for(auto j : c) {
            long long int var;
            if(j == i + 1) var = 1;
            else if(j > i + 1) var = 0;
            else var = ways[i - j];
            sum_ += var;
            sum_ %= MOD;
        }
        ways[i] = sum_;
    }
    return ways[x - 1] % MOD;
}


int main() {
    long long int n, x;
    cin >> n >> x;
    vector<long long int> c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    cout << Coin_Combs_I(n, x, c) << endl;
    return 0;
}   