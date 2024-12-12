#include <iostream>
#include <string.h>
using namespace std;
class hero{
private:
    int health;
    int level;
    char *name;
public:
    static int time;
    // Default constructor
    hero() {
        name = new char[100];
    }

    // Parameterized constructor
    hero(int health, int level, char *name) {
        this->health = health;
        this->level = level;
        this->name = name;
    }

    // Example of shallow copy constructor
    hero(hero& copy) {
        this->health = copy.health;
        this->level = copy.level;
        char *n = new char[strlen(copy.name) + 1];
        strcpy(n, copy.name);
        n[strlen(copy.name)] = '\0';
        this->name = n;
    }
       
    // Desctuctor
    ~hero() {
        cout << "destructor called" << endl;
    }

    void print() {
        cout << "[";
        cout << health << ", ";
        cout << level << ", ";
        cout << name;
        cout << "]" << endl;
    }

    // Health
    void setHeath(int a) {
        health = a;
    }
    int gethealth() {
        return health;
    }

    // Level
    void setlevel(int a) {
        level = a;
    }
    int getlevel() {
        return level;
    }

    // Name
    void setname(char *n) {
        name = n;
    }
    char *getname() {
        return name;
    }

    static int random() {
        return time;
    }

};
int hero::time = 10;
int main() {

    // cout << hero::time << endl;
    // cout << hero::random() << endl;
    // hero a;
    // cout << a.time << endl;
    // cout << a.random() << endl;
    // hero a;
    // a.time = 100;
    // cout << a.time << endl;
    // hero b;
    // b.time = 20;
    // cout << a.time << endl;
    // cout << b.time << endl;

    char name[] = "Ramesh";
    hero a(100, 2, name);
    cout << "a -> ";
    a.print();

    hero b = a;

    cout << "b -> ";
    b.print();

    name[0] = 'J';

    cout << "a -> ";
    a.print();

    cout << "b -> ";
    b.print();


    // {
    //     hero a;
    //     hero *b = new hero;    
    //     delete b;
    // }

    // hero ramesh1(100, 2);
    // cout << ramesh1.gethealth() << endl;
    // cout << ramesh1.getlevel() << endl;
    
    // hero ramesh2(ramesh1);
    // cout << ramesh2.gethealth() << endl;
    // cout << ramesh2.getlevel() << endl;
    
    // hero ramesh;
    // ramesh.level = 2;
    // cout << ramesh.level << endl;
    // ramesh.setHeath(100);
    // cout << ramesh.gethealth() << endl;
    // hero *ramesh1 = new hero;
    // // ramesh1->level = 2;
    // // cout << ramesh1->level << endl;
    // // ramesh1->setHeath(100);
    // cout << ramesh1->gethealth() << endl;
    return 0;
}