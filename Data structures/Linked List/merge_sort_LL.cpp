#include <iostream>
#include "AAASingly_LL.h"
using namespace std;
Node<int>* solve(Node<int>* list1, Node<int>* list2) {
    Node<int> *ptr1 = nullptr;
    if(list1 == nullptr || list2 == nullptr) {
        ptr1 = list1 ? list1 : list2;
        return ptr1;
    }
    ptr1 = list1->data < list2->data ? list1 : list2;
    Node<int> *ptr2 = nullptr;
    if(list1->data < list2->data) {
        ptr2 = solve(list1->next, list2);
    }
    else {
        ptr2 = solve(list1, list2->next);
    }
    ptr1->next = ptr2;
    return ptr1;
}
Node<int> *mergeSort(Node<int> *head) {
    if(head == nullptr || head->next == nullptr) return head;
    Node<int> *fast = head;
    Node<int> *slow = head;
    while(fast->next) {
        if(fast->next->next == nullptr) { 
            fast = fast->next;
        }
        else { 
            fast = fast->next->next;
            slow = slow->next;
        }
    }
    fast = slow->next;
    slow->next = nullptr;
    head = mergeSort(head);
    fast = mergeSort(fast);
    head = solve(head, fast);
    return head;
}
int main() {
    LinkedList<int> l;
    l.addEnd(12);
    l.addEnd(7);
    l.addEnd(13);
    l.addEnd(14);
    l.addEnd(2);
    l.addEnd(18);
    l.addEnd(9);
    l.addEnd(16);
    l.addEnd(12);
    l.addEnd(6);
    l.addEnd(19);
    l.addEnd(17);
    l.addEnd(15);
    l.addEnd(3);
    l.addEnd(11);
    l.addEnd(5);
    l.addEnd(10);
    l.addEnd(4);
    l.addEnd(8);
    l.addEnd(1);
    l.printList_1D();
    Node<int> *h = mergeSort(l.getHead());
    while(h) {
        cout << h->data << " ";
        h = h->next;
    }
    return 0;
}