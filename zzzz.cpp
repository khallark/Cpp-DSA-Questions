#include <iostream>
#include <myList.h>
using namespace std;

int main() {;
    List l = {{1, '2', true}, {"3", {4.99999999999999999999999999999999999}}};
    cout << l;
    return 0;
}