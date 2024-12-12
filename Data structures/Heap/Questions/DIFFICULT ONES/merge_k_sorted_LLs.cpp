#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int data;
	Node* next;
	
    Node() : next(nullptr) {}
	Node(int x){
	    data = x;
	    next = nullptr;
	}
	
}; 

class LinkedList : private Node {
    Node *head;
    Node *tail;
    int sizeLL = 1;
public:

    // Constructors
    ~LinkedList() {deleteEntireList();}
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Get functions
    Node *getHead() {
        return head;
    }
    Node *getTail() {
        return tail;
    }
    int size() {
        return this->sizeLL;
    }

    // List manipulating functions
    void addBeg(const int& data) {
        Node *temp;
        if(head == nullptr && tail == nullptr) {
            temp = new Node(data);
            head = temp;
            tail = temp;
            return;
        }
        temp = new Node(data);
        temp->next = head;
        head = temp;
        temp = nullptr;
        sizeLL++;
    }
    void addEnd(const int& data) {
        Node *temp;
        if(head == nullptr && tail == nullptr) {
            temp = new Node(data);
            head = temp;
            tail = temp;
            return;
        }
        temp = new Node(data);
        tail->next = temp;
        tail = temp;
        temp = nullptr;
        sizeLL++;
    }
    void addAtPos(int pos, const int& data) {
        if(pos <= 0) return;
        if(pos == 1) {
            addBeg(data);
            return;
        }
        int i = 0;
        Node *temp = head;
        if(temp == nullptr) return;
        while(i < pos - 2) {
            temp = temp->next;
            if(temp == nullptr) return;
            i++;
        }
        if(temp->next == nullptr) {
            addEnd(data);
            return;
        }
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
        sizeLL++;
    }
    void deleteBeg() {
        if(head == nullptr && tail == nullptr) return;
        Node *temp = head;
        if(head == tail) {
            head = nullptr;
            tail = nullptr;
            delete temp;
            temp = nullptr;
            return;
        }
        head = head->next;
        delete temp;
        temp = NULL;
        sizeLL--;
    }
    void deleteEnd() {
        if(head == nullptr && tail == nullptr) return;
        Node *temp = head;
        if(temp->next == nullptr) {
            deleteBeg();
            return;
        }
        while(temp->next->next) {
            temp = temp->next;
        }
        Node *ptr = temp->next;
        temp->next = nullptr;
        tail = temp;
        delete ptr;
        ptr = nullptr;
        sizeLL--;
    }
    void deleteFromPos(int pos) {
        if(head == nullptr && tail == nullptr) return;
        if(pos <= 0) return;
        if(pos == 1) {
            deleteBeg();
            return;
        }
        int i = 0;
        Node *temp = head;
        if(temp->next == nullptr) return;
        while(i < pos - 2) {
            temp = temp->next;
            if(temp->next == nullptr) return;
            i++;
        }
        if(temp->next->next == nullptr) {
            deleteEnd();
            return;
        }
        Node *ptr = temp->next;
        temp->next = ptr->next;
        delete ptr;
        ptr = nullptr;
        sizeLL--;
    }
    void deleteEntireList() {
        Node *temp = head;
        head = head->next;
        while(head) {
            delete temp;
            temp = head;
            head = head->next;
        }
        delete temp;
        temp = head;
        head = nullptr;
        tail = nullptr;
        sizeLL = 0;
    }

    // Data accessing operator overloading
    int& operator[](int index) {
        try {
            if (index < 0) {
                throw std::out_of_range("Index cannot be negative");
            }
            Node* current = head;
            int currentIndex = 0;
            while (current != nullptr && currentIndex < index) {
                current = current->next;
                currentIndex++;
            }
            if (current == nullptr) {
                throw std::out_of_range("Index out of bounds");
            }
            return current->data;
        } catch (const std::out_of_range& e) {
            std::cerr << "Out of bounds error: " << e.what() << std::endl;
            throw; 
        }
    }

    // Prints 1D list only
    void printList_1D() {
        if(head == nullptr && tail == nullptr) {
            cout << "(null)" << endl;
            return;
        }
        Node *temp = head;
        int i = 0;
        while(temp && (i == 0 || temp != head)) {
            cout << temp->data << " ";
            temp = temp->next;
            i++;
        }
        cout << endl;
    }
};



class compare {
    public:
    bool operator()(Node *a, Node *b) {
        return a->data > b->data;
    }
};

//Function to merge K sorted linked list.
Node * mergeKLists(Node *arr[], int K) {
    priority_queue<Node*, vector<Node*>, compare> q;
    for(int i = 0; i < K; i++) {
        q.push(arr[i]);
    }
    
    Node *dummy = new Node(-1);
    Node *ans = dummy;

    while(q.size()) {
        Node *temp = q.top();
        dummy->next = temp;
        dummy = dummy->next;
        q.pop();
        if(temp->next) {
            q.push(temp->next);
        }
    }
    return ans->next;
}

int main() {
    LinkedList l1;
    l1.addEnd(1);
    l1.addEnd(2);
    l1.addEnd(3);
    LinkedList l2;
    l2.addEnd(4);
    l2.addEnd(5);
    LinkedList l3;
    l3.addEnd(5);
    l3.addEnd(6);
    LinkedList l4;
    l4.addEnd(7);
    l4.addEnd(8);
    Node *arr[] = {l1.getHead(), l2.getHead(), l3.getHead(), l4.getHead()};
    int K = sizeof(arr) / sizeof(arr[0]);
    Node *ans = mergeKLists(arr, K);
    while(ans) {
        cout << ans->data << " ";
        ans = ans->next;
    }
    return 0;
}

