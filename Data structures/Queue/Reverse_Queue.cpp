#include <iostream>
#include <queue>
#include <stack>
using namespace std;
queue<int> rev(queue<int> q) {
    stack<int> s;
    while(!q.empty()) {
        int data = q.front();
        q.pop();
        s.push(data);
    }
    while(!s.empty()) {
        int data = s.top();
        s.pop();
        q.push(data);
    }
    return q;
}
int main() {
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);
    queue<int> newq = rev(q);
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    while (!newq.empty())
    {
        cout << newq.front() << " ";
        newq.pop();
    }
    cout << endl;
    return 0;
}