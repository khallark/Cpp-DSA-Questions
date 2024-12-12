#include <iostream>
#include <map>
#include "AAASingly_LL.h"
using namespace std;
void EliminateLoop1(Node<int> *head) {
    Node<int> *slow = head;
    Node<int> *fast = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) break; 
    }
    if(fast == nullptr || fast->next == nullptr) return;
    if(fast == head) {
        while(fast->next != head) {
            fast = fast->next;
        }
        fast->next = nullptr;
        return;
    }
    slow = head;
    while(slow->next != fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = nullptr;
}
void EliminateLoop2(Node<int> *head) {
    map<Node<int> *, bool> visitied;
    Node<int> *temp = head;
    while(temp) {
        if(visitied[temp->next]) {
            temp->next = nullptr;
            break;
        } 
        visitied[temp] = true;
        temp = temp->next;
    }
}
int main() {
    LinkedList<int> ll;
    for(int i = 0; i < 12; i++)
        ll.addEnd(i + 1);
    ll.printList_1D();
    ll.getTail()->next = ll.getHead();
    EliminateLoop2(ll.getHead());
    ll.printList_1D();
    return 0;
}