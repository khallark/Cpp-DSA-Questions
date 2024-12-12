#include <iostream>
#include "AAASingly_LL.h"
using namespace std;
Node<char>* solve(Node<char>* list1, Node<char>* list2) {
    Node<char> *ptr1 = nullptr;
    if(list1 == nullptr || list2 == nullptr) {
        ptr1 = list1 ? list1 : list2;
        return ptr1;
    }
    ptr1 = list1->data < list2->data ? list1 : list2;
    Node<char> *ptr2 = nullptr;
    if(list1->data < list2->data) {
        ptr2 = solve(list1->next, list2);
    }
    else {
        ptr2 = solve(list1, list2->next);
    }
    ptr1->next = ptr2;
    return ptr1;
}
Node<char> *mergeSort(Node<char> *head) {
    if(head == nullptr || head->next == nullptr) return head;
    Node<char> *fast = head;
    Node<char> *slow = head;
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
    LinkedList<char> l; {
        l.addEnd('q');
        l.addEnd('w');
        l.addEnd('e');
        l.addEnd('r');
        l.addEnd('t');
        l.addEnd('y');
        l.addEnd('u');
        l.addEnd('i');
        l.addEnd('o');
        l.addEnd('p');
        l.addEnd('a');
        l.addEnd('s');
        l.addEnd('d');
        l.addEnd('f');
        l.addEnd('g');
        l.addEnd('h');
        l.addEnd('j');
        l.addEnd('k');
        l.addEnd('l');
        l.addEnd('z');
        l.addEnd('x');
        l.addEnd('c');
        l.addEnd('v');
        l.addEnd('b');
        l.addEnd('m');
        l.addEnd('n');
    }
    l.printList_1D();
    Node<char> *h = mergeSort(l.getHead());
    while(h) {
        cout << h->data << " ";
        h = h->next;
    }
    return 0;
}