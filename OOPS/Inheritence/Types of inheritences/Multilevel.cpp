#include <iostream>
using namespace std;
class animal {
public:
    // properties
    int age;
    int weight;
    
    // functions
    void speak() {
        cout << "Speaking" << endl;
    }
};
// Inheritance 1
//      ↓
//      ↓
//      ↓
class dog : public animal {
    // Everything inherited from animal in {Public} mode
};
// Inheritance 2 
//      ↓
//      ↓
//      ↓
class german_shepherd : public dog {
    // Everything inherited from dog in {Public} mode
};
int main() {
    german_shepherd c;
    c.age = 2;
    c.weight = 23;
    c.speak();
    cout << c.age << endl;
    cout << c.weight << endl;
    return 0;
}