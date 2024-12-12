#include <iostream>
using namespace std;
class A {
public:
    void func() {
        cout << "I am A" << endl;
    }
};
class B {
public:
    void func() {
        cout << "I am B" << endl;
    }
};
class c : public A, public B{
};
int main() {
    c object;
    object.B::func();
    object.A::func();
    return 0;
}