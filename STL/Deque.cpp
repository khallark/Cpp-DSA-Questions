#include <iostream>
#include <deque>
using namespace std;
int main() {
    deque<int> a;
    a.push_back(1);
    a.push_front(2);
    a.push_back(3);
    a.push_front(4);
    a.push_back(5);
    a.push_front(6);
    a.push_back(7);
    a.push_front(8);
    a.push_back(9);
    a.push_front(10);
    for(int i:a) {
        cout << i << " ";
    }
    a.pop_back();
    cout << endl;
    for(int i:a) {
        cout << i << " ";
    }
    a.pop_front();
    cout << endl;
    for(int i:a) {
        cout << i << " ";
    }
    a.erase(a.begin() + 2, a.begin() + 5);
    cout << endl;
    for(int i:a) {
        cout << i << " ";
    }
    cout << endl << a.at(3);
    return 0;
}