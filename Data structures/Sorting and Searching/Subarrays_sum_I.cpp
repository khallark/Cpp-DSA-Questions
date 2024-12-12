#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<int> nums(n);
    for(auto& i : nums) cin >> i;
    int i = 0, j = 0;
    ll sum = 0;
    int count = 0;
    while(j < n) {
        sum += nums[j];
        while(sum >= x) {
            if(sum == x) count++;
            sum -= nums[i++];
        }
        j++;
    }
    cout << count << endl;
    return 0;
}