#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
vector<int> nextGreaterElement(vector<int> a) {
    stack<int> s;
    vector<int> ans(a.size());
    s.push(-1);
    int n = a.size() - 1;
    while(n >= 0) {
        while(s.top() != -1 && s.top() <= a[n]) 
            s.pop();
        ans[n] = s.top();
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
    while(n < a.size()) {
        while(s.top() != -1 && s.top() <= a[n]) 
            s.pop();
        ans[n] = s.top();
        s.push(a[n]);
        n++;
    }
    return ans;
}
// vector<int> nextGreaterElement(vector<int> a) {
//     stack<int> s;
//     vector<int> ans(a.size());
//     s.push(-1);
//     int n = a.size() - 1;
//     int max = -1;
//     while(n >= 0) {
//         while(s.top() != -1 && s.top() <= a[n]) 
//             s.pop();
//         max = s.top() > max ? s.top() : max;
//         ans[n] = s.top() == -1 ? s.top() : max;
//         s.push(a[n]);
//         n--;
//     }
//     return ans;
// }
// vector<int> prevGreaterElement(vector<int> a) {
//     stack<int> s;
//     vector<int> ans(a.size());
//     s.push(-1);
//     int n = 0;
//     int max = -1;
//     while(n < a.size()) {
//         while(s.top() != -1 && s.top() <= a[n]) 
//             s.pop();
//         max = s.top() > max ? s.top() : max;
//         ans[n] = s.top() == -1 ? s.top() : max;
//         s.push(a[n]);
//         n++;
//     }
//     return ans;
// }
int main() {
    vector<int> a = {5,4,7,3,8,2,3,5,9,5,6,3,7,5,2,6,4,8,4,5,2,0};
    a = prevGreaterElement(a);
    for(auto i: a) {
        cout << i << " ";
    }
    return 0;
}