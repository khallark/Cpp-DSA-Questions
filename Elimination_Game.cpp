#include <iostream>
using namespace std;
// int solve(int s, int w, int e) {
//     if(s == e) return s;
//     int s_temp = s + (w / 2);
//     int i = s;
//     while(1) {
//         if(i == e) {
//             e = e - (w / 2);
//             break;
//         }
//         else if((w > 0 && i + w > e) || (w < 0 && i + w < e)) break;
//         i = i + w;
//     }
//     int ans = solve(e, 0 - (2 * w), s_temp);
//     return ans;
// }
int solve(int s, int w, int e) {
    if(s == e) return s;
    int temp1 = s > e ? s : e;
    if(temp1 % w != 0) {
        e = e - (w / 2);
    }
    s = s + (w / 2);
    int ans = solve(e, -2 * w, s);
    return ans;
}
int lastRemaining(int n) {
    if(n == 1) {
        return 1;
    }
    return 2 * (n / 2 + 1 - lastRemaining(n / 2));
}
int main() {
    int n = 20;
    int ans = lastRemaining(n);
    cout << ans << endl;
    return 0;
}