#include <iostream>
using namespace std;
class A {
public:
    void func() {
        cout << "This is a function" << endl;
    }
    string func(string a) {
        return a;
    }
};
int main() {
    A obj;
    obj.func();
    cout << obj.func("yoyo") << endl;
    return 0;
}