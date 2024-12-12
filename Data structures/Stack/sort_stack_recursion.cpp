#include <iostream>
#include <stack>
using namespace std;
void sort_it(stack<int> &stack, int num) {
    if(stack.empty() || stack.top() >= num) {
        stack.push(num);
        return;
    }
    int curr = stack.top();
    stack.pop();
    sort_it(stack, num);
    stack.push(curr);
}
void SortStack(stack<int> &stack) {
    if(stack.empty()) {
        return;
    }
    int curr = stack.top();
    stack.pop();
    SortStack(stack);
    sort_it(stack, curr);
}
int main() {
    stack<int> s;
    s.push(3);
    s.push(5);
    s.push(5);
    s.push(8);
    s.push(4);
    s.push(1);
    s.push(7);
    s.push(7);
    s.push(6);
    s.push(2);
    SortStack(s);
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}