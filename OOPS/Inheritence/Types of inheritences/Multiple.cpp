#include <iostream>
using namespace std;
class animal {
public:
    void bark() {
        cout << "Barking" << endl;
    }
};
class human {
public:
    void speak() {
        cout << "speaking" << endl;
    } 
};
class hybrid : public animal, public human {
    // All members of classes animal and humans inherited
};
int main() {
    hybrid var;
    var.bark();
    var.speak();
    return 0;
}