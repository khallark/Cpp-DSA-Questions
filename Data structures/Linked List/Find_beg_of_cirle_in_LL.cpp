#include <iostream>
#include <map>
#include "AAASingly_LL.h"
using namespace std;
Node<int> *findBeg1(Node<int> *head) {
    Node<int> *slow = head;
    Node<int> *fast = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) break; 
    }
    slow = head;
    if(fast == nullptr || fast->next == nullptr) return nullptr;
    while(slow != fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
Node<int> *findBeg2(Node<int> *head) {
    map<Node<int> *, bool> visited;
    Node<int> *temp = head;
    while(temp) {
        if(visited[temp]) break;
        visited[temp] = true;
        temp = temp->next;
    }
    return temp;
}
int main() {
    LinkedList<int> ll;
    for(int i = 0; i < 12; i++)
        ll.addEnd(i + 1);
    ll.printList_1D();
    ll.getTail()->next = ll.getHead();
    cout << findBeg2(ll.getHead())->data << endl;
    return 0;
}