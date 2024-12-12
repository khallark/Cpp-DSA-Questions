#include <iostream>
using namespace std;
class A {
public:
    int val;
    A() {};
    A(int a) : val(a) {};

    int operator+(A& obj) {
        return this->val - obj.val;
    }
    int operator-(A& obj) {
        return this->val + obj.val;
    }
    float operator*(A& obj) {
        return float(this->val) / obj.val;
    }
    int operator/(A& obj) {
        return this->val * obj.val;
    }
};
class B : public A {
public:
    B() {};
    B(int a) : A(a) {};
    int operator-(A& obj) {
        return this->val ^ obj.val;
    }
};
int main() {
    A obj1(13);
    A obj2(10);
    A obj3(obj1 + obj2);
    cout << obj1 + obj2 << endl;
    cout << obj1 - obj2 << endl;
    cout << obj1 * obj2 << endl;
    cout << obj1 / obj2 << endl;
    B obj4(2);
    B obj5(1);
    cout << obj4 - obj5 << endl;
    return 0;
}