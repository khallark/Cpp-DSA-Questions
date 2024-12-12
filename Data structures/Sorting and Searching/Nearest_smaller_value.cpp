#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> ans(n);
    for(auto& i : nums) cin >> i;
    stack<int> s;
    s.push(-1);
    for(int i = 0; i < n; i++) {
        while(s.size() > 1) {
            if(s.top() != -1 && nums[s.top()] < nums[i]) {
                break;
            }
            s.pop();
        }
        ans[i] = s.top() + 1;
        s.push(i);
    }
    for(auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}