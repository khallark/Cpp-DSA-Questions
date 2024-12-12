#include <iostream>
#include <array>
using namespace std;
int main() {    
    array<int, 4> a = {1, 2}; 
    int size = a.size();
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
    cout << endl << a.at(2) << endl;
    cout << a.size() << endl;
    cout << a.empty() << endl;
    cout << a.front() << endl;
    cout << a.back() << endl;
    cout << a.max_size() << endl;
    // and many more......
    return 0;  
}