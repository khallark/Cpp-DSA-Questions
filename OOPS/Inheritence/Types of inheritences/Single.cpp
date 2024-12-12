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
class dog : public animal {
    // Everything inherited from animal in {Public} mode 
};
int main() {
    dog d;
    d.age = 2;
    d.weight = 23;
    d.speak();
    cout << d.age << endl;
    cout << d.weight << endl;
    return 0;
}