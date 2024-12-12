#include <iostream>
#include "AAASingly_LL.h"
using namespace std;
Node<int> *reverseList(Node<int> *head) {
    if(head == nullptr || head->next == nullptr) return head;
    Node<int> *prev = nullptr;
    Node<int> *curr = head;
    while(curr) {
        Node<int> *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
Node<int> *compute(Node<int> *head) {
    head = reverseList(head);
    Node<int> *prev = head;
    Node<int> *curr = head->next;
    int maxi = prev->data;
    while(curr) {
        if(curr->data < maxi) {
            prev->next = curr->next;
            curr = curr->next;
        }
        else {
            maxi = curr->data;
            curr = curr->next;
            prev = prev->next;
        }
    }
    return reverseList(head);
}
int main() {
    LinkedList<int> l;
    l.addEnd(12);
    l.addEnd(15);
    l.addEnd(10);
    l.addEnd(11);
    l.addEnd(5);
    l.addEnd(6);
    l.addEnd(2);
    l.addEnd(3);
    l.printList_1D();
    Node<int> *h = compute(l.getHead());
    while(h) {
        cout << h->data << " ";
        h = h->next;
    }
    return 0;
}