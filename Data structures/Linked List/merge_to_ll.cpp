#include <iostream>
#include "AAASingly_LL.h"
using namespace std;
Node<int> *mergeTwoLists(Node<int> *l1, Node<int> *l2) {
    if(l1 == nullptr || l2 == nullptr) return l1 ? l1 : l2;
    Node<int> *smaller = l1->data <= l2->data ? l1 : l2;
    Node<int> *ptr = l1->data <= l2->data ? mergeTwoLists(l1->next, l2) : mergeTwoLists(l1, l2->next);
    smaller->next = ptr;
    return smaller;
}
int main() {
    LinkedList<int> ll1;
    ll1.addEnd(2);
    ll1.addEnd(4);
    ll1.addEnd(6);
    ll1.printList_1D();
    LinkedList<int> ll2;
    ll2.addEnd(1);
    ll2.addEnd(3);
    ll2.addEnd(5);
    ll2.printList_1D();
    Node<int> *h = mergeTwoLists(ll1.getHead(), ll2.getHead());
    while(h) {
        cout << h->data << " ";
        h = h->next;
    }
    exit(1);
    return 0;
}