#include "AAAnode.cpp"
#include <climits>
using namespace std;

// This Function could also be Implemented using Morris Traversal, which would save the Recursive Stack Space.
void solve(Node *root, Node* &prev, Node* &n1, Node* &n2) {
    if(root == nullptr) return;
    solve(root->left, prev, n1, n2);
    if(prev->d > root->d) {
        n1 = !n1 ? prev : n1;
        n2 = root;
    }
    prev = root;
    solve(root->right, prev, n1, n2);
}
void recoverBST(Node *root) {
    Node *n1 = nullptr, *n2 = nullptr;
    Node *prev = new Node(INT_MIN);
    solve(root, prev, n1, n2);
    swap(n1->d, n2->d);
}

void inorder(Node *root) {
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->d << " ";
    inorder(root->right);
}

int main() {
    Node *root = nullptr;
    cout << "Input - "; root = build_from_level_order(root);
    // 7 4 22 1 10 20 30 -1 3 -1 -1 -1 21 -1 -1 -1 -1 -1 -1
    cout << "INORDER Before recovering - ";
    inorder(root);
    cout << endl;
    recoverBST(root);
    cout << "INORDER after recovering - ";
    inorder(root);
    return 0;
}