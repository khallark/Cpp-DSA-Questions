#include <iostream>
#include "AAASingly_LL.h"
using namespace std;
Node<int> *reverseList_recusive(Node<int> *head, int k, int i) {
    if(i == k - 1)
        return head;
    Node<int> *ptr = reverseList_recusive(head->next, k, i + 1);
    Node<int> *temp = head->next;
    temp->next = head;
    head->next = nullptr;
    return ptr;
}
Node<int> *reverseList_iterative(Node<int> *head, int k, int i) {
    if(head == nullptr || head->next == nullptr) return head;
    Node<int> *prev = nullptr;
    Node<int> *curr = head;
    while(i < k) {
        Node<int> *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        i++;
    }
    return prev;
}
Node<int>* reverseKGroup(Node<int>* head, int k) {
    Node<int> *ret = head;
    Node<int> *p = nullptr;
    Node<int> *h = head;
    Node<int> *t = head;
    int i = 0;
    while(t) {
        if(t->next == nullptr && p == nullptr)
            return reverseList_iterative(h, k, 0);
        if(i == k - 1) {
            i = 0;
            Node<int> *temp = t->next;
            t = reverseList_iterative(h, k, i);
            swap(t, h);
            t->next = temp;
            if(p == nullptr) ret = h;
            else p->next = h;
            p = t;
            t = t->next;
            h = t;
        }
        t = t != nullptr ? t->next : t;
        i++;
    }
    // In case we also want to reverse the remaining list:
    /*if(h != nullptr) {
        t = h;
        while(t->next) t = t->next;
        t = reverseList_iterative(h, i, 0);
        swap(t, h);
        t->next = nullptr;
        p->next = h;
    }*/
    return ret;
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
    ll.addEnd(10);
    ll.addEnd(11);
    ll.addEnd(12);
    ll.printList_1D();
    Node<int> *h = reverseKGroup(ll.getHead(), 3);
    while(h) {
        cout << h->data << " ";
        h = h->next;
    }
    return 0;
}