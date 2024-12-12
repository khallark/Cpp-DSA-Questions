#include <iostream>
#include "AAASingly_LL.h"
using namespace std;
Node<int> *moveLastToFirst(Node<int> *head) {
    if(head == nullptr || head->next == nullptr) return head;
    Node<int> *temp1 = head;
    while(temp1->next->next) {
        temp1 = temp1->next;
    }
    Node<int> *temp2 = temp1->next;
    temp2->next = head;
    temp1->next = nullptr;
    return temp2;
}
int main() {
    LinkedList<int> l;
    l.addEnd(1);
    l.addEnd(2);
    l.addEnd(3);
    l.addEnd(4);
    l.addEnd(5);
    l.addEnd(6);
    l.addEnd(7);
    l.addEnd(8);
    l.printList_1D();
    Node<int> *h = l.getHead();
    h = moveLastToFirst(h);
    while(h) {
        cout << h->data << " ";
        h = h->next;
    }
    return 0;
}