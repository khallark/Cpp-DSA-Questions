#include <iostream>
#include "AAASingly_LL.h"
using namespace std;
int main() {
    LinkedList<int> l1;
    l1.addEnd(1);
    l1.addEnd(2);
    l1.addEnd(3);
    l1.addEnd(4);
    l1.addEnd(5);
    LinkedList<int> l2;
    l2.addEnd(6);
    l2.addEnd(7);
    l2.addEnd(8);
    l2.addEnd(9);
    l2.addEnd(10);
    LinkedList<LinkedList<int>> l;
    l.addEnd(l1);
    l.addEnd(l2);
    for(int i = 0; i < l.size(); i++) {
        for(int j = 0; j < l[i].size(); j++) {
            cout << l[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}