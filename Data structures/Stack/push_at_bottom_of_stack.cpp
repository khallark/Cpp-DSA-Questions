#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int>& s, int x) {
    if(s.empty()) {
        s.push(x);
        return;
    }
    int curr = s.top();
    s.pop();
    solve(s, x);
    s.push(curr);
}
stack<int> pushAtBottom(stack<int> s, int x) {
    solve(s, x);
    return s;
}
int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s = pushAtBottom(s, 4);
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}