#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int minimumCoins(int n, int x, vector<int> &c) {
    vector<int> mini(x);
    int mini_ = INT_MAX;
    for(auto i : c) {
        int var;
        if(i == 0 + 1) var = 1;
        else if(i > 0 + 1) var = -1;
        if(var != -1) mini_ = min(mini_, i);
    }
    mini[0] = mini_ == INT_MAX ? -1 : mini_;
    for(int i = 1; i < x; i++) {
        int mini_ = INT_MAX;
        for(auto j : c) {
            int var;
            if(j == i + 1) var = 1;
            else if(j > i + 1) var = -1;
            else var = mini[i - j] == -1 ? -1 : mini[i - j] + 1;
            if(var != -1) mini_ = min(mini_, var);
        }
        mini[i] = mini_ == INT_MAX ? -1 : mini_;
    }
    return mini[x - 1];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    cout << minimumCoins(n, x, c) << endl;
    return 0;
}