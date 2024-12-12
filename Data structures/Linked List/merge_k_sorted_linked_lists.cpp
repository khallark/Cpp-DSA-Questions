#include <iostream>
#include "AAASingly_LL.h"
using namespace std;
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
Node<int> *mergeKLists(Node<int> *arr[], int K) {
    Node<int> *masterList = nullptr;
    for(int i = 0; i < K; i++) {
        masterList = mergeTwoLists(masterList, arr[i]);
    }
    return masterList;
}
int main() {
    LinkedList<int> l1;
    l1.addEnd(1);
    l1.addEnd(2);
    l1.addEnd(3);
    LinkedList<int> l2;
    l2.addEnd(4);
    l2.addEnd(5);
    LinkedList<int> l3;
    l3.addEnd(5);
    l3.addEnd(6);
    LinkedList<int> l4;
    l4.addEnd(7);
    l4.addEnd(8);
    Node<int> *h1 = l1.getHead();
    Node<int> *h2 = l2.getHead();
    Node<int> *h3 = l3.getHead();
    Node<int> *h4 = l4.getHead();
    Node<int> *arr[] = {h1, h2, h3, h4};
    int K = sizeof(arr) / sizeof(h1);
    Node<int> *masterList = mergeKLists(arr, K);
    while(masterList) {
        cout << masterList->data << " ";
        masterList = masterList->next;
    }
    return 0;
}