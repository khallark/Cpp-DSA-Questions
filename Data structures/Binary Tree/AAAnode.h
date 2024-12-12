#include <iostream>
#include <queue>
// #include <windowsx.h>
using namespace std;
class Node {
public:
    int d;
    Node *left;
    Node *right;
    Node(int val) {
        this->d = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *build_from_level_order(Node *root) {
    queue<Node*> q;
    cout << "Enter the data for root Node : ";
    int data;
    cin >> data;
    if(data == -1) {
        return root;
    }
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        int data;
        cin >> data;
        if(data != -1) {
            temp->left = new Node(data);
            q.push(temp->left);
        }
        cin >> data;
        if(data != -1) {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }
    return root;
}