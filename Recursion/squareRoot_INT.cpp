#include <iostream>
using namespace std;
int BinSearch(int x, int s, int e) {
    if(s > e) return e;
    int mid = s + (e - s) / 2;
    int ans = mid;
    if(mid * mid == x) return mid;
    else if(mid * mid < x) ans = BinSearch(x, mid + 1, e);
    else ans = BinSearch(x, s, mid - 1);
    return ans;
}
int squareRoot(int x) {
    int limit = x <= 46340 ? x : 46340;
    return BinSearch(x, 0, limit);
}
int main() {
    cout << squareRoot(36) << endl;
    return 0;
}