#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
Node *build_from_level_order(Node *root) {
    queue<Node*> q;
    cout << "Enter the data for root node : ";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();

        cout << "Enter the left value of node " << temp->data << " : ";
        int data;
        cin >> data;
        if(data != -1) {
            temp->left = new Node(data);
            q.push(temp->left);
        }

        cout << "Enter the right value of node " << temp->data << " : ";
        cin >> data;
        if(data != -1) {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }
    return root;
}


void getInorder(Node *root, vector<int>& v) {
    if(root == nullptr) {
        return;
    }
    getInorder(root->left, v);
    v.push_back(root->data);
    getInorder(root->right, v);
}
void preorderFromInorder(Node *root, vector<int> v, int& i) {
    if(root == nullptr) {
        return;
    }
    root->data = v[i++];
    preorderFromInorder(root->left, v, i);
    preorderFromInorder(root->right, v, i);
}
void bst_to_minHeap(Node *root) {
    vector<int> v;
    cout << endl;
    getInorder(root, v);
    int i = 0;
    preorderFromInorder(root, v, i);
}


void preorder(Node *root) {
    if(root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root) {
    if(root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main() {
    Node *root = build_from_level_order(root);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    // 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    bst_to_minHeap(root);
    cout << endl << endl << "PreOrder - ";
    preorder(root);
    cout << endl << "InOrder  - ";
    inorder(root);
}