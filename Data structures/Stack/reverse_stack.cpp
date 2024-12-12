#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<int>& s, int x) {
    if(s.empty()) {
        s.push(x);
        return;
    }
    int curr = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(curr);
}
void reverseStack(stack<int>& s) {
    if(s.empty()) {
        return;
    }
    int curr = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, curr);
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
    reverseStack(s);
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}