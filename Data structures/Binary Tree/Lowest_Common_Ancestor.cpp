#include <iostream>
#include "AAAnode.h"
using namespace std;
Node* lca(Node* root ,int n1 ,int n2 ) {
    if(root == nullptr) {
        return nullptr;
    }
    if(root->d == n1 || root->d == n2) {
        return root;
    }

    Node *temp1 = lca(root->left, n1, n2);
    Node *temp2 = lca(root->right, n1, n2);

    if(temp1 && !temp2) {
        return temp1;
    }
    else if(!temp1 && temp2) {
        return temp2;
    }
    else if(temp1 && temp2) {
        return root;
    }
    else {
        return nullptr;
    }
}
int main() {
    Node *root = build_from_level_order(root);
    // 1 2 3 4 5 -1 -1 -1 -1 8 6 10 -1 7 -1 11 12 -1 9 13 14 -1 -1 -1 -1 -1 -1 -1 15 -1 -1
    cout << endl << endl << lca(root, 15, 4)->d << endl;
}