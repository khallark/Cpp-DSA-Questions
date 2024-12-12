#include <iostream>
#include "AAAnode.cpp"
using namespace std;

pair<Node*, Node*> BTtoLLInorder(Node *root) {
    if(root == nullptr) return {nullptr, nullptr};

    Node *head = root, *tail = root;
    
    pair<Node*, Node*> left = BTtoLLInorder(root->left);
    pair<Node*, Node*> right = BTtoLLInorder(root->right);

    if(left.second) {
        left.second->right = head;
        head->left = left.second;
        head = left.first;
    }

    if(right.first) {
        right.first->left = root;
        root->right = right.first;
        tail = right.second;
    }

    return {head, tail};
}
pair<Node*, Node*> BTtoLLPreorder(Node *root) {
    if(root == nullptr) return {nullptr, nullptr};

    Node *tail = root;
    
    pair<Node*, Node*> left = BTtoLLPreorder(root->left);
    pair<Node*, Node*> right = BTtoLLPreorder(root->right);

    tail->left = nullptr;

    if(left.first) {
        left.first->left = tail;
        tail->right = left.first;
        tail = left.second;
    }

    if(right.first) {
        right.first->left = tail;
        tail->right = right.first;
        tail = right.second;
    }

    return {root, tail};
}
pair<Node*, Node*> BTtoLLPostorder(Node *root) {
    if(root == nullptr) return {nullptr, nullptr};

    Node *head = root;
    
    pair<Node*, Node*> left = BTtoLLPostorder(root->left);
    pair<Node*, Node*> right = BTtoLLPostorder(root->right);

    head->right = nullptr;

    if(right.second) {
        right.second->right = head;
        head->left = right.second;
        head = right.first;
    }

    if(left.second) {
        left.second->right = head;
        head->left = left.second;
        head = left.first;
    }

    return {head, root};
}

int main() {
    Node *root = nullptr;
    root = build_from_level_order(root);
    // 1 2 5 3 4 -1 6 -1 -1 -1 -1 -1 -1
    Node *head = BTtoLLPreorder(root).first;
    while(head) {
        cout << head->d << " ";
        head = head->right;
    }
    return 0;
}