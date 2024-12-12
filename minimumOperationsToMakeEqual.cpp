#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <limits.h>
using namespace std;
int solve(int x, int y, unordered_map<int, bool>& m) {
    if(m[x]) {
        return INT_MAX;
    }
    m[x] = true;
    if(x == y) {
        return 0;
    }
    int v1 = INT_MAX, v2 = INT_MAX, v3 = INT_MAX, v4 = INT_MAX;
    if(x % 5 == 0) {
        v1 = solve(x / 5, y, m);
    }
    if(x % 11 == 0) {
        v2 = solve(x / 11, y, m);
    }
    if(x > y && x % 5 != 0 && x % 11 != 0) {
        v3 = solve(x - 1, y, m);
    }
    if(x < y || x % 5 != 0 && x % 11 != 0) {
        v4 = solve(x + 1, y, m);
    }
    return min({v1, v2, v3, v4}) + 1;
}
int minimumOperationsToMakeEqual(int x, int y) {
    unordered_map<int, bool> m;
    return solve(x, y, m);
}
int main() {
    int x = 54;
    int y = 2;
    int MinOps = minimumOperationsToMakeEqual(x, y);
    printf("%d", MinOps);
    return 0;
}