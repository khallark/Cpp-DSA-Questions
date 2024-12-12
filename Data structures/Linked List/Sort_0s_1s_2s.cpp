#include <iostream>
#include <map>
#include "AAASingly_LL.h"
void sort012_1(Node<int> *head) {
    map<int, int> count;
    Node<int> *temp = head;
    while(temp) {
        count[temp->data]++;
        temp = temp->next;
    }
    temp = head;
    for(int i = 0; i <= 2; i++) {
        while(count[i]) {
            temp->data = i;
            count[i]--;
            temp = temp->next;
        }
    }
}
Node<int> *sort012_2(Node<int> *head) {
    Node<int> *list_0 = nullptr;
    Node<int> *list_0t = nullptr;
    Node<int> *list_1 = nullptr;
    Node<int> *list_1t = nullptr;
    Node<int> *list_2 = nullptr;
    Node<int> *list_2t = nullptr;
    Node<int> *temp = head;
    while(temp) {
        if(temp->data == 0) {
            if(list_0) {
                list_0->next = temp;
                list_0t = temp;
            }
            else {
                list_0 = temp;
                list_0t = temp;
            }
        }
        if(temp->data == 1) {
            if(list_1) {
                list_1->next = temp;
                list_1t = temp;
            }
            else {
                list_1 = temp;
                list_1t = temp;
            }
        }
        if(temp->data == 2) {
            if(list_2) {
                list_2->next = temp;
                list_2t = temp;
            }
            else {
                list_2 = temp;
                list_2t = temp;
            }
        }
        Node<int> *nextNode = temp->next;
        temp->next = nullptr;
        temp = nextNode;
    }
    if(list_0) {
        temp = list_0;
    }
    else if(list_1) {
        temp = list_1;
    }
    else if(list_2) {
        temp = list_2;
    }
    if(list_0) {
        if(list_1) list_0t->next = list_1;
        else if(list_2) list_0t->next = list_2;
    }
    else if(list_1) list_1t->next = list_2;
    return temp;
}
int main() {
    LinkedList<int> obj;
    obj.addEnd(1);
    obj.addEnd(2);
    obj.addEnd(2);
    obj.addEnd(2);
    obj.addEnd(1);
    obj.printList_1D();
    Node<int> *h = sort012_2(obj.getHead());
    // obj.printList();
    while(h) {
        cout << h->data << " ";
        h = h->next;
    }
    return 0;
}