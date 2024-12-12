#include <iostream>
#include <vector>
#include <set>
#include "AAASingly_LL.h"
using namespace std;
int main() {
    LinkedList<int> l1;
    l1.addEnd(4);
    l1.addBeg(2);
    l1.addEnd(5);
    l1.addBeg(1);
    l1.addAtPos(3, 3);
    LinkedList<int> l2;
    l2.addEnd(4);
    l2.addBeg(2);
    l2.addEnd(5);
    l2.addBeg(1);
    l2.addAtPos(3, 3);
    LinkedList<int> l3;
    l3.addEnd(4);
    l3.addBeg(2);
    l3.addEnd(5);
    l3.addBeg(1);
    l3.addAtPos(3, 3);
    LinkedList<int> l4;
    l4.addEnd(8);
    l4.addBeg(1);
    l4.addEnd(6);
    l4.addBeg(3);
    l4.addAtPos(3, 9);
    LinkedList<int> l5;
    l5.addEnd(5);
    l5.addBeg(8);
    l5.addEnd(1);
    l5.addBeg(6);
    l5.addAtPos(3, 2);
    LinkedList<int> l6;
    l6.addEnd(9);
    l6.addBeg(7);
    l6.addEnd(3);
    l6.addBeg(1);
    l6.addAtPos(3, 6);
    LinkedList<int> l7;
    l7.addEnd(23);
    l7.addBeg(65);
    l7.addEnd(98);
    l7.addBeg(43);
    l7.addAtPos(3, 7);
    LinkedList<LinkedList<int>> l;
    l.addEnd(l1);
    l.addEnd(l2);
    l.addEnd(l3);
    l.addEnd(l4);
    l.addEnd(l5);
    l.addEnd(l6);
    l.addEnd(l7);
    l.deleteFromPos(3);
    Node<LinkedList<int>> *head = l.getHead();
    while(head) {
        Node<int> *h = head->data.getHead();
        cout << "(";
        while(h) {
            cout << h->data << " ";
            h = h->next;
        }
        head = head->next;
        cout << ") ";
    }
    return 0;
}