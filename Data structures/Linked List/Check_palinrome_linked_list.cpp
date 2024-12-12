#include <iostream>
#include <map>
#include "AAASingly_LL.h"
using namespace std;
bool checkPalindrome(Node<int> *head1, Node<int>* &head2) {
    if(head1 == nullptr) return true;
    bool check = true;
    check = checkPalindrome(head1->next, head2);
    if(check == false) return false;
    if(head1->data == head2->data) {
        head2 = head2->next;
        return true;
    }
    else {
        head2 = head2->next;
        return false;
    }
}
int main() {
    LinkedList<int> ll;
    ll.addEnd(1);
    ll.addEnd(2);
    ll.addEnd(3);
    ll.addEnd(4);
    ll.addEnd(3);
    ll.addEnd(2);
    ll.addEnd(1);
    ll.printList_1D();
    Node<int> *h = ll.getHead();
    cout << checkPalindrome(h, h) << endl;
    return 0;
}