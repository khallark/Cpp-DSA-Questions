#include <iostream>
using namespace std;
class The_origin_Class {
public:
    int height = 12;
    int weight = 53;
    int age = 21;
    string color = "Pink";
};
//      ↓
//      ↓
//      ↓
//      ↓
//      ↓
//      ↓
//      ↓
//      ↓
//      ↓
//      ↓
//      ↓

// FIRST:
class A1_inherited_from_origin : public The_origin_Class{
public:
    void getHeight() {
        cout << this->height << endl; 
    }
    void getWeight() {
        cout << this->weight << endl; 
    }
};
//      ↓
//      ↓
class A11_inherited_from_A1 : public A1_inherited_from_origin {
    void getAge() {
        cout << this->age << endl; 
    }
};
class A12_inherited_from_A1 : public A1_inherited_from_origin {
    void getColor() {
        cout << this->color << endl; 
    }
};

// SECOND:
class A2_inherited_from_origin : public The_origin_Class{
public:
    void getAge() {
        cout << this->age << endl; 
    }
    void getColor() {
        cout << this->color << endl; 
    }
};
//      ↓
//      ↓
class A21_inherited_from_A1 : public A2_inherited_from_origin {
    void getHeight() {
        cout << this->height << endl; 
    }
};
class A22_inherited_from_A1 : public A2_inherited_from_origin {
    void getWeight() {
        cout << this->weight << endl; 
    }
};