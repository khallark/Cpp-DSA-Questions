#include <iostream>
#include "AAASingly_LL.h"
using namespace std;
Node<int> *reverseList_recusive(Node<int> *head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    Node<int> *ptr = reverseList_recusive(head->next);
    Node<int> *temp = head->next;
    temp->next = head;
    head->next = nullptr;
    return ptr;
}
Node<int> *reverseList_iterative(Node<int> *head) {
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
int main() {
    LinkedList<int> ll;
    ll.addEnd(1);
    ll.addEnd(2);
    ll.addEnd(3);
    ll.addEnd(4);
    ll.addEnd(5);
    ll.addEnd(6);
    ll.addEnd(7);
    ll.addEnd(8);
    ll.addEnd(9);
    ll.printList_1D();
    return 0;
}