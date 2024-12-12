#include <iostream>
#include <vector>
#include "AAASingly_LL.h"
using namespace std;
vector<Node<int>*> partitioning_small_pivot_large(Node<int>* head) {
    vector<Node<int>*> retVect;
    Node<int> *smallHead = new Node<int>(-1);
    Node<int> *smallTail = smallHead;
    Node<int> *midHead = new Node<int>(-1);
    midHead->next = head;
    Node<int> *bigHead = new Node<int>(-1);
    Node<int> *BigTail = bigHead;
    Node<int> *temp = head->next;
    while(temp) {
        if(head->data >= temp->data) {
            smallTail->next = temp;
            smallTail = smallTail->next;
        }
        else {
            BigTail->next = temp;
            BigTail = BigTail->next;
        }
        temp = temp->next;
    }
    smallTail->next = nullptr;
    midHead->next->next = nullptr;
    BigTail->next = nullptr;
    retVect.push_back(smallHead->next);
    retVect.push_back(midHead->next);
    retVect.push_back(bigHead->next);
    return retVect;
}
Node<int> *QuickSort(Node<int> *head) {
    if(head == nullptr || head->next == nullptr) return head;
    vector<Node<int>*>arr = partitioning_small_pivot_large(head);
    Node<int> *small = QuickSort(arr[0]);
    Node<int> *big = QuickSort(arr[2]);
    Node<int> *retHead = small ? small : arr[1];

    while(small && small->next) small = small->next;

    if(small) small->next = arr[1];

    else retHead = arr[1];

    arr[1]->next = big;
    return retHead;
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

    /*
    cout << endl;
    vector<Node<int>*> a = partitioning_small_pivot_large(l.getHead());
    cout << "- ";
    while(a[0]) {
        cout << a[0]->data << " ";
        a[0] = a[0]->next;
    }
    cout << endl << "- " ;
    while(a[1]) {
        cout << a[1]->data << " ";
        a[1] = a[1]->next;
    }
    cout << endl << "- ";
    while(a[2]) {
        cout << a[2]->data << " ";
        a[2] = a[2]->next;
    }
    */

    Node<int> *h = QuickSort(l.getHead());
    while(h) {
        cout << h->data << " ";
        h = h->next;
    }
    return 0;
}