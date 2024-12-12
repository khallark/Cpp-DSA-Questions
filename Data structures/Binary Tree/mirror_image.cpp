#include <iostream>
#include "AAAnode.h"
using namespace std;
void levelOrderTraversal(Node *root) {
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if(temp == nullptr) {
            cout << endl;
            if(!q.empty()) {
                q.push(nullptr);
            }
        }
        else {
            cout << temp->d << " ";
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}
void mirrorify1(Node* root, Node* &mirror) {
    queue<Node*> q;
    queue<Node*> m;
    q.push(root);
    mirror = new Node(root->d);
    m.push(mirror);
    while(!q.empty()) {
        Node *temp1 = q.front();
        Node *temp2 = m.front();
        q.pop();
        m.pop();
        if(temp1->right) {
            temp2->left = new Node(temp1->right->d);
            m.push(temp2->left);
            q.push(temp1->right);
        }
        if(temp1->left) {
            temp2->right = new Node(temp1->left->d);
            m.push(temp2->right);
            q.push(temp1->left);
        }
    }
}
void mirrorify2(Node* root, Node* &mirror) {
    if(root == nullptr) return;
    mirror = new Node(root->d);
    mirrorify2(root->right, mirror->left);
    mirrorify2(root->left, mirror->right);
}
int main() {
    Node *root = build_from_level_order(root);
    Node *mirror;
    mirrorify2(root, mirror);
    levelOrderTraversal(mirror);
    return 0;
}