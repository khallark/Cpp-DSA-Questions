#include <iostream>
#include <queue>
#include <stack>
using namespace std;
template <typename data>
class node {
public:
    data d;
    node<data> *left;
    node<data> *right;
    node(data val) {
        this->d = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
node<int> *build_from_level_order(node<int> *root) {
    queue<node<int>*> q;
    cout << "Enter the data for root node : ";
    int data;
    cin >> data;
    root = new node<int>(data);
    q.push(root);

    while(!q.empty()) {
        node<int> *temp = q.front();
        q.pop();

        cout << "Enter the left value of node " << temp->d << " : ";
        int data;
        cin >> data;
        if(data != -1) {
            temp->left = new node<int>(data);
            q.push(temp->left);
        }

        cout << "Enter the right value of node " << temp->d << " : ";
        cin >> data;
        if(data != -1) {
            temp->right = new node<int>(data);
            q.push(temp->right);
        }
    }
    return root;
}
void inorder_recursive(node<int> *root) { // Print in order (Left-Current-Right)
    if(root == nullptr) return;
    inorder_recursive(root->left); //left
    cout << root->d << " "; // node
    inorder_recursive(root->right); // right
}
void inorder_iterative(node<int> *root) {
    stack<node<int>*> s;
    node<int> *current = root;
    while(!s.empty() || current) {
        while(current) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        cout << current->d << " ";
        
        current = current->right;
    }
}
int main() {
    node<int> *root = nullptr;
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // 1 4 6 2 3 9 -1 -1 -1 8 -1 -1 -1 -1 -1
    root = build_from_level_order(root);
    inorder_iterative(root);
    return 0;
}