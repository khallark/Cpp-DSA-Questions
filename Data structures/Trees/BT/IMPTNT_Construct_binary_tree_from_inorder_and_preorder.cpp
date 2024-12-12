#include <iostream>
#include <queue>
#include <unordered_map>
#include "AAAnode.cpp"
using namespace std;

Node *solve(vector<int> &preorder, unordered_map<int, int> &indexes, int i1, int j1, int i2, int j2) {
    if(i1 > j1) return nullptr;
    int k = indexes[preorder[i2]];
    Node *root = new Node(preorder[i2]);
    root->left = solve(preorder, indexes, i1, k - 1, i2 + 1, i2 + (k - i1));
    root->right = solve(preorder, indexes, k + 1, j1, j2 - (j1 - k) + 1, j2);
    return root;
}

Node *construct(vector<int> &inorder, vector<int> &preorder) {
    unordered_map<int, int> indexes;
    int count = 0;
    for(auto i : inorder) indexes[i] = count++;
    Node *root = solve(preorder, indexes, 0, inorder.size() - 1, 0, preorder.size() - 1);
    return root;
}

void level_order(Node *root) {
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()) {
        Node *temp = q.front();
        cout << temp->d << " ";
        q.pop();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        if(q.front() == nullptr) {
            cout << endl;
            q.pop();
            if(!q.empty()) q.push(nullptr);
        }
    }
}

int main() {
    vector<int> inorder = {1, 9};
    vector<int> preorder = {9, 1};
    Node *root = construct(inorder, preorder);
    level_order(root);
}
