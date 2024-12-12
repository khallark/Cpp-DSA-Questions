#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.front() << " " << s.size() << endl;
    cout << s.empty() << endl;
    s.pop();
    cout << s.front() << " " << s.size() << endl;
    cout << s.empty() << endl;
    s.pop();
    cout << s.front() << " " << s.size() << endl;
    cout << s.empty() << endl;
    s.pop();
    return 0;
}