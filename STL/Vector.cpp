#include <iostream>
#include <vector>
using namespace std;
int main() {  
    vector<int> a;
    a.push_back(1);
    cout << a.capacity() << " " << a.size() << endl;
    a.push_back(2);
    cout << a.capacity() << " " << a.size() << endl;
    a.push_back(3);
    cout << a.capacity() << " " << a.size() << endl;
    a.push_back(4);
    cout << a.capacity() << " " << a.size() << endl;
    a.push_back(5);
    cout << a.capacity() << " " << a.size() << endl;
    a.push_back(6);
    cout << a.capacity() << " " << a.size() << endl;
    a.push_back(7);
    cout << a.capacity() << " " << a.size() << endl;
    a.push_back(8);
    cout << a.capacity() << " " << a.size() << endl;
    a.push_back(9);
    cout << a.capacity() << " " << a.size() << endl;
    cout << ".at(4) : " << a.at(4) << endl;
    cout << "Before pop_back()" << endl;
    for (int i:a) {
        cout << i << " ";
    }
    a.pop_back();
    cout << endl << "After pop_back()" << endl;
    for (int i:a) {
        cout << i << " ";
    }
    cout << endl << "Size before clear : " << a.size() << endl;
    a.clear();
    cout << "Size after clear : " << a.size() << endl;

    vector<int> v(10, 2);
    for(int i:v) {
        cout << i << " ";
    }
    cout << endl;
    vector<int> copycat(v);
    for(int i:copycat) {
        cout << i << " ";
    }
    return 0;
}