#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(auto& i : nums) cin >> i;
    ll count = 0;
    int i = 0, j = 0;
    ll distincts = 0;
    map<int, ll> m;
    while(j < n) {
        if(m[nums[j]] == 0) distincts++;
        m[nums[j]]++;
        while(distincts > k) {
            m[nums[i]]--;
            if(m[nums[i]] == 0) distincts--;
            i++;
        }
        count += j - i + 1;
        j++;
    }
    cout << count << endl;
    return 0;
}