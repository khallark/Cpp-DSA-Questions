#include <iostream>
#include <map>
#include "AAASingly_LL.h"
using namespace std;
void removeDups(Node<int> *head) {
    if(head == nullptr || head->next == nullptr) return;
    Node<int> *curr = head;
    while(curr) {
        if(curr->next && curr->next->data == curr->data) curr->next = curr->next->next;
        else curr = curr->next;
    }
}
int main() {
    LinkedList<int> obj;
    obj.addEnd(1);
    obj.addEnd(1);
    obj.addEnd(2);
    obj.addEnd(2);
    obj.addEnd(3);
    obj.addEnd(3);
    obj.addEnd(4);
    obj.addEnd(4);
    obj.addEnd(5);
    obj.addEnd(5);
    obj.addEnd(6);
    obj.addEnd(6);
    obj.printList_1D();
    removeDups(obj.getHead());
    obj.printList_1D();
    return 0;
}