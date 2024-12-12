#include <iostream>
#include <set>
using namespace std;
int main() {
    set<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(1);
    s.insert(8);
    s.insert(2);
    s.insert(2);
    s.insert(6);
    for(int i:s) {
        cout << i << " ";
    }
    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);
    cout << endl;
    for(int i:s) {
        cout << i << " ";
    }
    cout << endl << s.count(-6) << endl;
    set<int>::iterator itr = s.find(8);
    cout << *itr << endl;
    return 0;
}