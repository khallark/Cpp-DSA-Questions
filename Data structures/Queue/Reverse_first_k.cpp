#include <iostream>
#include <queue>
#include <stack>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;
    int data;
    int n = q.size() - k;
    while(k) {
        data = q.front();
        q.pop();
        s.push(data);
        k--;
    }
    while(!s.empty()) {
        data = s.top();
        s.pop();
        q.push(data);
    }
    while(n) {
        data = q.front();
        q.pop();
        q.push(data);
        n--;
    }
    return q;
}
int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    queue<int> newq = modifyQueue(q, 7);
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