#include <iostream>
#include "AAASingly_LL.h"
using namespace std;
Node<int> *middleOfList(Node<int> *head) {
    Node<int> *fast = head;
    Node<int> *slow = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
int main() {
    LinkedList<int> ll;
    ll.addEnd(1);
    ll.addEnd(2);
    ll.addEnd(3);
    ll.addEnd(4);
    ll.addEnd(5);
    // ll.addEnd(6);
    // ll.addEnd(7);
    // ll.addEnd(8);
    // ll.addEnd(9);
    ll.printList_1D();
    cout << middleOfList(ll.getHead())->data << endl;
    return 0;
}