#include <iostream>
using namespace std;
class A {
public:
    void speak() {
        cout << "Speaking" << endl;
    }
};
class B : public A {
public:
    void speak() {
        cout << "Barking" << endl;
    }
};
int main() {
    B obj;
    obj.speak();
    return 0;
}