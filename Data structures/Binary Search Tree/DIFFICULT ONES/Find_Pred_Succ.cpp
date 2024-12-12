#include "AAABuild_Bst.h"
using namespace std;

Node *findMin(Node *root) {
    while(root->left) {
        root = root->left;
    }
    return root;
}

Node *findMax(Node *root) {
    while(root->right) {
        root = root->right;
    }
    return root;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    pre = nullptr;
    suc = nullptr;
    Node *temp = root;
    while(temp) {
        if(temp->data > key) {
            suc = temp;
            temp = temp->left;
        }
        else if(temp->data < key) {
            pre = temp;
            temp = temp->right;        
        }
        else {
            break;
        }
    }
    if(temp && temp->left) {
        pre = findMax(temp->left);
    }
    if(temp && temp->right) {
        suc = findMin(temp->right);
    }
}

int main() {
    Node *root = nullptr;
    vector<int> v = {10, 2, 11, 1, 5, 3, 7, 4};
    root = build_bst(root, v);
    Node *pre;
    Node *suc;
    findPreSuc(root, pre, suc, 1);
    if(pre) cout << pre->data << ", ";
    else cout << "NULL, ";
    if(suc) cout << suc->data << endl;
    else cout << "NULL" << endl;
    return 0;
}