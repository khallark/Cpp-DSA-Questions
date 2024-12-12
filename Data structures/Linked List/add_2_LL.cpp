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
Node<int> *addTwoNumbers(Node<int> *l1, Node<int> *l2) {
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    Node<int> *ret = l1;
    Node<int> *temp1;
    int carry = 0;
    while(l1 || l2 || carry) {
        int sum = 0;
        if(l1) sum += l1->data;
        if(l2) sum += l2->data;
        if(l1 == nullptr && l2 == nullptr) {
            Node<int> *newNode = new Node<int>(carry);
            temp1->next = newNode;
            break;
        }
        if(l1 == nullptr) {
            l2->data = (sum + carry) % 10;
            carry = (sum + carry) / 10;
            temp1->next = l2;
            temp1 = temp1->next;
            l2 = l2->next;
            continue;
        }
        l1->data = (sum + carry) % 10;
        carry = (sum + carry) / 10;
        temp1 = l1;
        l1 = l1->next;
        l2 = l2 ? l2->next : l2;
    }
    return reverseList(ret);
}
int main() {
    LinkedList<int> l1;
    l1.addEnd(3);
    l1.addEnd(4);
    l1.printList_1D();
    LinkedList<int> l2;
    l2.addEnd(2);
    l2.addEnd(3);
    l2.addEnd(0);
    l2.addEnd(5);
    l2.addEnd(6);
    l2.addEnd(1);
    l2.printList_1D();
    Node<int> *sum = addTwoNumbers(l1.getHead(), l2.getHead());
    while(sum) {
        cout << sum->data << " ";
        sum = sum->next;
    }
    return 0;
}