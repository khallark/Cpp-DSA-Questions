#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> nextGreaterElement(vector<int> a) {
    stack<int> s;
    vector<int> ans(a.size());
    s.push(-1);
    int n = a.size() - 1;
    int max = -1;
    while(n >= 0) {
        while(s.top() != -1 && s.top() <= a[n]) 
            s.pop();
        max = s.top() > max ? s.top() : max;
        ans[n] = s.top() == -1 ? s.top() : max;
        s.push(a[n]);
        n--;
    }
    return ans;
}
vector<int> prevGreaterElement(vector<int> a) {
    stack<int> s;
    vector<int> ans(a.size());
    s.push(-1);
    int n = 0;
    int max = -1;
    while(n < a.size()) {
        while(s.top() != -1 && s.top() <= a[n]) 
            s.pop();
        max = s.top() > max ? s.top() : max;
        ans[n] = s.top() == -1 ? s.top() : max;
        s.push(a[n]);
        n++;
    }
    return ans;
}
int trap(vector<int>& height) {
    vector<int> prev(height.size());
    prev = prevGreaterElement(height);
    vector<int> next(height.size());
    next = nextGreaterElement(height);
    int ans = 0;
    int left = -1;
    int right = -1; 
    for(int i = 0; i < height.size(); i++) {
        int l = prev[i];
        int r = next[i];
        if(l == -1) left = -1;
        else left = l > left ? l : left;
        if(r == -1) right = -1;
        else right = r > right ? r : right;
        if(l == -1 || r == -1) {
            cout << height[i] << ", " << 0 << endl;    
            continue;
        }
        ans += (left < right ? left : right) - height[i];
        cout << height[i] << ", " << (left < right ? left : right) - height[i] << endl;
    }
    return ans;
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 6, 8, 9};
    cout << trap(arr) << endl;
    return 0;
}