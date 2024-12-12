#include <iostream>
#include <vector>
#include <queue>
using namespace std;
long long minCost(long long arr[], long long n) {
    if(n == 1) return 0;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    for(long long i = 0; i < n; i++) {
        q.push(arr[i]);
    }
    long long ans = 0;
    while(q.size() != 1) {
        long long r1 = q.top();
        q.pop();
        long long r2 = q.top();
        q.pop();
        cout << r1 + r2 << endl;
        ans += r1 + r2;
        q.push(r1 + r2);
    }
    return ans;
}
int main() {
    long long arr[] = {4, 3, 2, 6};
    long long n = sizeof(arr) / sizeof(arr[0]);
    cout << minCost(arr, n);
    return 0;
}