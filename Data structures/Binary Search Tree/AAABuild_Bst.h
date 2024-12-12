#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        this->data = d;
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

        cout << "Enter the left value of Node " << temp->data << " : ";
        int data;
        cin >> data;
        if(data != -1) {
            temp->left = new Node(data);
            q.push(temp->left);
        }

        cout << "Enter the right value of Node " << temp->data << " : ";
        cin >> data;
        if(data != -1) {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }
    return root;
}

void levelOrderTraversal(Node *root) {
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if(temp == nullptr) {
            cout << "| ";
            if(!q.empty()) {
                q.push(nullptr);
            }
        }
        else {
            cout << temp->data << " ";
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void inorder_recursive(Node*root) { // Print in order (Left-Current-Right)
    if(root == nullptr) return;
    inorder_recursive(root->left); //left
    cout << root->data << " "; // node
    inorder_recursive(root->right); // right
}

void PreOrder_recursive(Node *root) { // Print in order (Current-Left-Right)
    if(root == nullptr) return;
    cout << root->data << " "; // node
    PreOrder_recursive(root->left); // left
    PreOrder_recursive(root->right); // right
}

void PostOrder_recursive(Node *root) { // Print in order (Left-Right-Current)
    if(root == nullptr) return;
    PostOrder_recursive(root->left); // left
    PostOrder_recursive(root->right); // right
    cout << root->data << " "; // node
}

Node *place_node_to_right_position(Node* root, int value) {
    // base case
    if(root == nullptr) {
        root = new Node(value);
        return root;
    }

    // Left or right
    if(root->data >= value)
        root->left = place_node_to_right_position(root->left, value);
    if(root->data < value)
        root->right = place_node_to_right_position(root->right, value);

    // return current root
    return root;
}

Node *build_bst(Node* root, vector<int> values) {
    for(int i = 0; i < values.size(); i++) {
        root = place_node_to_right_position(root, values[i]);
    }
    return root;
}