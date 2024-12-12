#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> nums(n);
    for(auto& i : nums) cin >> i;
    vector<long long> ps(n + 1);
    ps[1] = nums[0];
    for(int i = 2; i <= n; i++) ps[i] = ps[i - 1] + nums[i - 1];
    vector<long long> ans(q);
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        ans[i] = ps[b] - ps[a - 1];
    }
    for(auto i : ans) cout << i << endl;
    return 0;
}