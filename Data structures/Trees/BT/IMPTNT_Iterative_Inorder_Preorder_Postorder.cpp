#include "AAAnode.cpp"
#include <stack>
#include <matrix.h>

vector<int> inorder_iterative(Node *root) {
    stack<Node*> s;
    vector<int> inorder;
    while(root) {
        s.push(root);
        root = root->left;
    }
    while(!s.empty()) {
        Node *temp = s.top(); 
        s.pop();
        inorder.push_back(temp->d);
        if(temp->right) {
            temp = temp->right;
            while(temp) {
                s.push(temp);
                temp = temp->left;
            }
        }
    }
    return inorder;
}

vector<int> preorder_iterative(Node *root) {
    stack<Node*> s;
    vector<int> preorder;
    s.push(root);
    while(!s.empty()) {
        Node *temp = s.top();
        s.pop();
        preorder.push_back(temp->d);
        if(temp->right) s.push(temp->right);
        if(temp->left) s.push(temp->left);
    }
    return preorder;
}

vector<int> postorder_iterative(Node *root) {
    stack<pair<Node*, bool>> s;
    vector<int> postorder;
    s.push({root, false});
    while(!s.empty()) {
        pair<Node*, bool> temp = s.top();
        s.pop();
        if(temp.second) {
            postorder.push_back(temp.first->d);
        }
        else {
            s.push({temp.first, true});
            if(temp.first->right) s.push({temp.first->right, false});
            if(temp.first->left) s.push({temp.first->left, false});
        }
    }
    return postorder;
}

int main() {
    Node *root = nullptr;
    cout << "Input - "; root = build_from_level_order(root);
    // 7 1 8 -1 5 -1 12 3 6 10 -1 2 4 -1 -1 9 11 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Inorder - " << inorder_iterative(root);
    cout << "Preorder - " << preorder_iterative(root);
    cout << "Postorder - " << postorder_iterative(root);
    return 0;
}