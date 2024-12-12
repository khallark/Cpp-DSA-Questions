#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << " " << s.size() << endl;
    s.pop();
    cout << s.top() << " " << s.size() << endl;
    cout << s.empty() << endl;
    return 0;
}