#include <iostream>
#include <stack>
using namespace std;
void deleteMiddle(stack<int>& s, int n) {
    stack<int> store;
    int num = n;
    num = (num / 2) + 1;
    while(num) {
        store.push(s.top());
        s.pop();
        num--;
    }
    store.pop();
    while(!store.empty()) {
        s.push(store.top());
        store.pop();
    }
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
    deleteMiddle(s, s.size());
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}