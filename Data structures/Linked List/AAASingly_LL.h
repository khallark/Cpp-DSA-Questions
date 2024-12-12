#include <iostream>
using namespace std;
template <typename DataType>
class Node {
public:
    DataType data;
    Node<DataType> *next;
    Node() : next(nullptr) {}
    Node(const DataType& d) : data(d), next(nullptr) {}
};

// Contains all the necessary properties and actions to create and 
// manipulate a Singly Linked List.
template <typename DataType>
class LinkedList : private Node<DataType> {
    Node<DataType> *head;
    Node<DataType> *tail;
    int sizeLL = 1;
public:

    // Constructors
    ~LinkedList() {deleteEntireList();}
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Get functions
    Node<DataType> *getHead() {
        return head;
    }
    Node<DataType> *getTail() {
        return tail;
    }
    int size() {
        return this->sizeLL;
    }

    // List manipulating functions
    void addBeg(const DataType& data) {
        Node<DataType> *temp;
        if(head == nullptr && tail == nullptr) {
            temp = new Node<DataType>(data);
            head = temp;
            tail = temp;
            return;
        }
        temp = new Node<DataType>(data);
        temp->next = head;
        head = temp;
        temp = nullptr;
        sizeLL++;
    }
    void addEnd(const DataType& data) {
        Node<DataType> *temp;
        if(head == nullptr && tail == nullptr) {
            temp = new Node<DataType>(data);
            head = temp;
            tail = temp;
            return;
        }
        temp = new Node<DataType>(data);
        tail->next = temp;
        tail = temp;
        temp = nullptr;
        sizeLL++;
    }
    void addAtPos(int pos, const DataType& data) {
        if(pos <= 0) return;
        if(pos == 1) {
            addBeg(data);
            return;
        }
        int i = 0;
        Node<DataType> *temp = head;
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
        Node<DataType> *newNode = new Node<DataType>(data);
        newNode->next = temp->next;
        temp->next = newNode;
        sizeLL++;
    }
    void deleteBeg() {
        if(head == nullptr && tail == nullptr) return;
        Node<DataType> *temp = head;
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
        Node<DataType> *temp = head;
        if(temp->next == nullptr) {
            deleteBeg();
            return;
        }
        while(temp->next->next) {
            temp = temp->next;
        }
        Node<DataType> *ptr = temp->next;
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
        Node<DataType> *temp = head;
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
        Node<DataType> *ptr = temp->next;
        temp->next = ptr->next;
        delete ptr;
        ptr = nullptr;
        sizeLL--;
    }
    void deleteEntireList() {
        Node<DataType> *temp = head;
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
    DataType& operator[](int index) {
        try {
            if (index < 0) {
                throw std::out_of_range("Index cannot be negative");
            }
            Node<DataType>* current = head;
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
        Node<DataType> *temp = head;
        int i = 0;
        while(temp && (i == 0 || temp != head)) {
            cout << temp->data << " ";
            temp = temp->next;
            i++;
        }
        cout << endl;
    }
};