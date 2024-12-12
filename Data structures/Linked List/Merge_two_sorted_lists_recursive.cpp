#include <iostream>
#include <map>
#include "AAASingly_LL.h"
Node<int>* mergeTwoLists(Node<int>* list1, Node<int>* list2) {
    Node<int> *ptr1 = NULL;
    if(list1 == NULL || list2 == NULL) {
        ptr1 = list1 ? list1 : list2;
        return ptr1;
    }
    ptr1 = list1->data < list2->data ? list1 : list2;
    Node<int> *ptr2 = NULL;
    if(list1->data < list2->data) {
        ptr2 = mergeTwoLists(list1->next, list2);
    }
    else {
        ptr2 = mergeTwoLists(list1, list2->next);
    }
    ptr1->next = ptr2;
    return ptr1;
}
int main() {
    LinkedList<int> ll1;
    ll1.addEnd(1);
    ll1.addEnd(2);
    ll1.addEnd(4);
    ll1.printList_1D();
    LinkedList<int> ll2;
    ll2.addEnd(1);
    ll2.addEnd(3);
    ll2.addEnd(4);
    ll2.printList_1D();
    Node<int> *h = mergeTwoLists(ll1.getHead(), ll2.getHead());
    while(h) {
        cout << h->data << " ";
        h = h->next;
    }
    return 0;
}