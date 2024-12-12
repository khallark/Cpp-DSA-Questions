#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<vector<int>> arr(n);
    int index = 0;
    for(auto& i : arr) {
        int val;
        cin >> val;
        i = {val, index++};
    }
    sort(arr.begin(), arr.end());
    int l = 0, r = n - 1;
    vector<int> ans;
    while(l <= r) {
        if(arr[l][0] + arr[r][0] == x) {
            ans = {arr[l][1], arr[r][1]};
            break;
        } else if(arr[l][0] + arr[r][0] < x) {
            l++;
        } else {
            r--;
        }
    }
    if(ans.empty() || ans[0] == ans[1]) cout << "IMPOSSIBLE" << endl;
    else cout << ans[0] + 1 << " " << ans[1] + 1 << endl;
    return 0;
}