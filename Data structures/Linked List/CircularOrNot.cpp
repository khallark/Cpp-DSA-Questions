#include <iostream>
#include <map>
#include "AAASingly_LL.h"
using namespace std;
bool isCircular1(Node<int> *head) {
    Node<int> *slow = head;
    Node<int> *fast = head;
    while(fast && fast->next) {
        if(fast == slow) return true;
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}
bool isCircular2(Node<int> *head) {
    if(head == nullptr) return false;
    map<Node<int> *, bool> visited;
    Node<int> *temp = head;
    while(temp) {
        if(visited[temp] == true) return true;
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
int main() {
    LinkedList<int> ll;
    for(int i = 0; i < 12; i++)
        ll.addEnd(i + 1);
    ll.getTail()->next = ll.getHead();
    cout << isCircular1(ll.getHead()) << endl;
    return 0;
}