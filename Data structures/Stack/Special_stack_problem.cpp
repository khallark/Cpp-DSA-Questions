#include <iostream>
#include <stack>
using namespace std;
class SpecialStack {
    public:
    stack<int> stack;
    int mini = 2147483647;
    void push(int data) {
        // Implement the push() function.
        if(stack.empty()) {
            stack.push(data);
            mini = data;
        }
        else {
         	if(data < mini) {
                stack.push(2*data - mini);
                mini = data;
            }   
            else {
                stack.push(data);
            }
        }
    }

    void pop() {
        // Implement the pop() function.
        if(stack.empty()) return;
        if(mini < stack.top()) {
            stack.pop();
        }
        else {
            mini = 2 * mini - stack.top();
            stack.pop();
        }
    }

    int top() {
        // Implement the top() function.
        if(stack.empty()) return -1;
        if(stack.top() < mini) {
            return mini;
        }
        else {
            return stack.top();
        }
    }

    int getMin() {
        // Implement the getMin() function.
        if(stack.empty()) return -1;
        return mini;
    }  
};
int main() {
    SpecialStack s;
    s.push(5);
    cout << s.getMin() << endl;
    s.push(3);
    cout << "3 here " << s.getMin() << endl;
    s.push(4);
    cout << s.getMin() << endl;
    s.push(6);
    cout << s.getMin() << endl;
    s.push(2);
    cout << "2 here " << s.getMin() << endl;
    s.push(8);
    cout << s.getMin() << endl;
    s.push(3);
    cout << s.getMin() << endl;
    s.push(5);
    cout << s.getMin() << endl;
    s.push(1);
    cout << "1 here " << s.getMin() << endl;
    s.push(7);
    cout << s.getMin() << endl;
    s.push(10);
    cout << s.getMin() << endl;
    cout << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << "2 here " << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << "3 here " << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << "0 here " << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    return 0;
}