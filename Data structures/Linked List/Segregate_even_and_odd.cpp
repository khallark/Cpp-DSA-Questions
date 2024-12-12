#include <iostream>
#include "AAASingly_LL.h"
using namespace std;
Node<int>* divide(int N, Node<int> *head) {
    Node<int> *prev = nullptr;
    Node<int> *curr = head;
    Node<int> *dummy1 = new Node<int>(-1);
    Node<int> *dummy2 = dummy1;
    int num;
    while(curr) {
        int num = curr->data;
        if(num&1) {
            if(prev == nullptr) prev = curr;
            else prev = prev->next;
            curr = curr->next; 
        }
        else {
            if(curr != head) {
                dummy1->next = curr;
                prev->next = curr->next;
                curr->next = nullptr;
                curr = prev->next;
                dummy1 = dummy1->next;
            }
            else {
                dummy1->next = curr;
                head = curr->next;
                curr->next = nullptr;
                curr = head;
                dummy1 = dummy1->next;
            }
        }
    }
    dummy1->next = head;
    return dummy2->next;
}
int main() {
    LinkedList<int> l;
    l.addEnd(17);
    l.addEnd(15);
    l.addEnd(8);
    l.addEnd(9);
    l.addEnd(2);
    l.addEnd(4);
    l.addEnd(6);
    l.printList_1D();
    Node<int> *h = divide(7, l.getHead());
    while(h) {
        cout << h->data << " ";
        h = h->next;
    }
    return 0;
}