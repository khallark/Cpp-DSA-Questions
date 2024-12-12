#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
vector<int> nextSmallerElement(vector<int> a) {
    stack<int> s;
    vector<int> ans(a.size());
    s.push(-1);
    int n = a.size() - 1;
    while(n >= 0) {
        while(s.top() != -1 && a[s.top()] >= a[n]) 
            s.pop();
        cout << s.top() << endl;
        ans[n] = s.top();
        s.push(n);
        n--;
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int> a) {
    stack<int> s;
    vector<int> ans(a.size());
    s.push(-1);
    int n = 0;
    while(n < a.size()) {
        while(s.top() != -1 && a[s.top()] >= a[n]) 
            s.pop();
        ans[n] = s.top();
        s.push(n);
        n++;
    }
    return ans;
}
int main() {
    vector<int> a = {73,74,75,71,69,72,76,73};
    a = nextSmallerElement(a);
    for(auto i: a) {
        cout << i << " ";
    }
    return 0;
}