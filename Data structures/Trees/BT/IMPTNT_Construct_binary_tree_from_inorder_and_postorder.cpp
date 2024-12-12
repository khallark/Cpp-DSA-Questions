#include <iostream>
#include <queue>
#include <unordered_map>
#include "AAAnode.cpp"
using namespace std;

Node *solve(vector<int> &postorder, unordered_map<int, int> &indexes, int i1, int j1, int i2, int j2) {
    if(i1 > j1) return nullptr;
    int k = indexes[postorder[j2]];
    Node *root = new Node(postorder[j2]);
    root->left = solve(postorder, indexes, i1, k - 1, i2, i2 + (k - i1) - 1);
    root->right = solve(postorder, indexes, k + 1, j1, j2 - (j1 - k), j2 - 1);
    return root;
}

Node *construct(vector<int> &inorder, vector<int> &postorder) {
    unordered_map<int, int> indexes;
    int count = 0;
    for(auto i : inorder) indexes[i] = count++;
    Node *root = solve(postorder, indexes, 0, inorder.size() - 1, 0, postorder.size() - 1);
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
    vector<int> inorder = {4, 10, 6, 2, 11, 3, 1, 5, 9, 8, 7};
    vector<int> postorder = {10, 2, 6, 3, 5, 1, 11, 4, 7, 8, 9};
    Node *root = construct(inorder, postorder);
    level_order(root);
    return 0;
}