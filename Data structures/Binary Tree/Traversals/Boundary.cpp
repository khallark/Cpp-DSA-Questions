#include <iostream>
#include <algorithm>
#include "C:\Users\ABC\Documents\C++\Data structures\Binary Tree\AAAnode.h"
using namespace std;

void getLeaves(Node *root, Node *r, vector<int>& leaves) {
    if(root == nullptr) { // Handles the situations where the node doesn't has both subtrees.
        return;
    }
    
    if(root->left == nullptr && root->right == nullptr) { // Identifies the leaf nodes.
        if(root != r) { // this ensures that if there is only the root node in the tree, it doesn't get added again.
            leaves.push_back(root->d);
        }
        return;
    }
    
    getLeaves(root->left, r, leaves);
    getLeaves(root->right, r, leaves);
}

vector<int> boundary(Node *root)
{
    vector<int> main; // keeps the actual nodes to be returned.
    vector<int> right; // although we could have just put the right boundes nodes directly into the main vector, but since the nodes need to be put in a reversed order, a vector is needed to reverse it.
    
    if(root) { // pushes the root node into the main vector.
        main.push_back(root->d);
    }
    
    Node *temp;

    // Pushes the leftmost nodes possible into the main vector.
    temp = root ? root->left : nullptr;
    while(temp && (temp->left || temp->right)) {
        main.push_back(temp->d);
        temp = temp->left ? temp->left : temp->right; // this ensures that the left most nodes get added, and not just the left subtree's nodes. (Very Important)
    }

    getLeaves(root, root, main);

    // Pushes the rightmost nodes possible into the main vector.
    temp = root ? root->right : nullptr;
    while(temp && (temp->right || temp->left)) {
        right.push_back(temp->d);
        temp = temp->right ? temp->right : temp->left; // this ensures that the right most nodes get added, and not just the right subtree's nodes. (Very Important)
    }
    // reverses the rightmost possible nodes and stores them into the main vector.
    reverse(right.begin(), right.end());
    for(auto i: right) {
        main.push_back(i);
    }

    return main; // returns the main vector.
}

int main() {
    Node *root = build_from_level_order(root);
    vector<int> ans = boundary(root);
    for(auto i : ans) {
        cout << i << " ";
    }
    return 0;
}