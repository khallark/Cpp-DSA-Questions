#include <iostream>
#include <map>
#include "AAASingly_LL.h"
using namespace std;
Node<int> *breakList(Node<int> *head) {
    if(head == nullptr || head->next == nullptr || head->next == head) return nullptr;
    if(head->next->next == head) {
        Node<int> *temp = head->next;
        head->next = head;
        temp->next = temp;
        return temp;
    }
    Node<int> *fast = head;
    Node<int> *slow = head;
    while(fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node<int> *temp = slow->next;
    slow->next = head;
    if(fast->next == head) fast->next = temp;
    else if(fast->next->next == head) fast->next->next = temp;
    return temp; 
}
int main() {
    LinkedList<int> object;
    for(int i = 0; i < 9324; i++) object.addEnd(i + 1);
    object.getTail()->next = object.getHead();
    Node<int> *h1 = object.getHead();
    Node<int> *h2 = breakList(h1);
    Node<int> *t = h1;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != h1);

    cout << endl << endl;

    t = h2;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != h2);
    exit(1);
    return 0;
}