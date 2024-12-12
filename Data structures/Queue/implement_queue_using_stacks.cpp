#include <iostream>
#include <stack>
using namespace std;
class StackQueue{
private:   
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
        s1.push(x);
    }
    int pop() {
        if(s1.empty()) return -1;
        int data;
        while(!s1.empty()) {
            data = s1.top();
            if(s1.size() > 1) {
                s2.push(s1.top());
            }
            s1.pop();
        }
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return data;
    }
    bool empty() {
        return s1.empty();
    }
};
int main() {
    StackQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while(!q.empty())
        cout << q.pop() << " ";
    return 0;
}