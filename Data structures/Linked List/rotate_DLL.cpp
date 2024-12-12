#include<iostream> 
using namespace std;

class Node { 
	public: 
		char data;
		Node* next;
		Node* pre;
	Node(int data) 
{ 
		this->data=data;
		pre=NULL;
		next=NULL;
	} 
};

void insertAtHead(Node* &head, int data) { 
	Node* n = new Node(data);
	if(head==NULL) 
{ 
		head=n;
		return;
	} 
	n->next=head;
	head->pre=n;
	head=n;
	return;
} 

void insertAtTail(Node* &head, int data) { 
	if(head==NULL) 
{ 
		insertAtHead(head,data);
		return;
	} 
	Node* temp=head;
	while(temp->next!=NULL) 
{ 
		temp=temp->next;
	} 
	Node* n=new Node(data);
	temp->next=n;
	n->pre=temp;
	return;
} 

void display(Node* head) { 
	while(head!=NULL) { 
		cout << head->data << " ";
		head=head->next;
	} 
} 

void rotateByN(Node* &head, int n) {
    Node *curr = head;
    Node *newHead = nullptr;
    Node *currTail = head;
    Node* temp;
    while(currTail->next) currTail = currTail->next;
    while(n) {
        temp = curr->next;
        currTail->next = curr;
        curr->pre = currTail;
        curr->next = nullptr;
        currTail = currTail->next;
        curr = temp;
        curr->pre = nullptr;
        n--;
        if(n == 0) {
            head = temp;
        }
    }
}

int main() { 
	Node* head=NULL;
	insertAtTail(head,'a');
	insertAtTail(head,'b');
	insertAtTail(head,'c');
	insertAtTail(head,'d');
	insertAtTail(head,'e');
	insertAtTail(head,'f');

	int n = 2;
	cout << "Given linked list \n";
	display(head);
	rotateByN(head,n);
	cout << "\nRotated Linked list \n";
	display(head);
	cout << "\n\n";

	return 0;
} 
