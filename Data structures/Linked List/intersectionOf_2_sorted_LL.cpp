#include <iostream>
#include "AAASingly_LL.h"
using namespace std;
Node<int> *intersection(Node<int> *h1, Node<int> *h2) {
    Node<int> *intersect = nullptr;
    Node<int> *prev = nullptr;
    while(h1 && h2) {
        if(h1->data == h2->data) {
            Node<int> *curr = new Node<int>(h1->data);
            if(intersect == nullptr) intersect = curr;
            if(prev == nullptr) prev = curr;
            else {
                prev->next = curr;
                prev = curr;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
        else if(h1->data < h2->data) h1 = h1->next;
        else h2 = h2->next;
    }
    return intersect;
}
int main() {
    LinkedList<int> l1;
    l1.addEnd(1);
    l1.addEnd(2);
    l1.addEnd(3);
    l1.addEnd(4);
    l1.addEnd(6);
    LinkedList<int> l2;
    l2.addEnd(1);
    l2.addEnd(2);
    l2.addEnd(3);
    l2.addEnd(6);
    Node<int> *h = intersection(l1.getHead(), l2.getHead());
    if(h == nullptr) cout << "No intersection found :(" << endl;
    while(h) {
        cout << h->data << " ";
        h = h->next;
    }
    return 0;
}