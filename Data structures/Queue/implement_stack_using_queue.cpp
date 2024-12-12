#include <iostream>
#include <queue>
using namespace std;
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int data) {
        q1.push(data);
    }
    int pop() {
        if(q1.empty()) return -1;
        int data;
        while(!q1.empty()) {
            data = q1.front();
            if(q1.size() > 1)
                q2.push(data);
            q1.pop();
        }
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return data;
    }
    bool empty() {
        return q1.empty();
    }
};
int main() {
    QueueStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    while(!s.empty())
        cout << s.pop() << " ";
    return 0;
}