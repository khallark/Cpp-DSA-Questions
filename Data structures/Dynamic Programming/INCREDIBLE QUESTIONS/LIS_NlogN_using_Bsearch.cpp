#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& i : nums) {
        cin >> i;
    }
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
        if (it == lis.end()) {
            lis.push_back(nums[i]);
        } else {
            *it = nums[i];
        }
    }
    cout << lis.size() << endl;
    return 0;
}