#include <iostream>
using namespace std;
class human {
private:
    int height = 100; // This variable cannot be accessed by anyone, accept this class.
protected:
    int weight = 50; // This variable cannot be accessed outside the class, but can be accesed by the inherited class.
public:
    int age = 15; // This variable can be accessed both outside the class, as well as by the inherited class.
};

class male1 : public human {
    int a = this->height; // private + public = {Not accessible}
    int b = this->weight; // protected + public = protected
    int c = this->age; // public + public = public
};
class male2 : protected human {
    int a = this->height; // private + protected = {Not accessible}
    int b = this->weight; // protected + protected = protected
    int c = this->age; // public + protected = protected
};
class male3 : private human {
    int a = this->height; // private + public = {Not accessible}
    int b = this->weight; // protected + private = private
    int c = this->age; // public + private = private
};
int main() {
    male1 m1;
    male2 m2;
    male3 m3;
    
    cout << m1.height << endl; // Not accessible, because it's a {private} member of class human
    cout << m1.weight << endl; // Not accessible, because it's a {protected} member of class m1
    cout << m1.age << endl; // Accessible, because it's a {public} member of class m1

    cout << m2.height << endl; // Not accessible, because it's a {private} member of class human
    cout << m2.weight << endl; // Not accessible, because it's a {protected} member of class m2
    cout << m2.age << endl; // Not accessible, because it's a {protected} member of class m2

    cout << m3.height << endl; // Not accessible, because it's a {private} member of class human
    cout << m3.weight << endl; // Not accessible, because it's a {private} member of class m3
    cout << m3.age << endl; // Not accessible, because it's a {private} member of class m3

    return 0;
}