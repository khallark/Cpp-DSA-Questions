#include "AAASingly_LL.h"
using namespace std;

Node<int> *reverse_list(Node<int> *head) {
    if(head->next == nullptr) {
        return head;
    }

    Node<int> *ptr = reverse_list(head->next);

    Node<int> *temp = head->next;
    head->next = nullptr;
    temp->next = head;

    return ptr;
}

int main() {
    LinkedList<int> l;
    for(int i = 0; i < 40; i++) {
        l.addEnd(i);
    }

    Node<int> *head = l.getHead();

    Node<int> *ptr = head;

    while(ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    ptr = reverse_list(head);
    
    cout << endl;
    while(ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}