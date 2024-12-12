#include "AAABuild_Bst.h"
using namespace std;
int LCAinaBST(Node *root, int P, int Q) {
    Node *node1, *node2;
    node1 = node2 = root;
    Node *temp = root;
    while (node1 && node2)
    {
        if(node1 != node2) {
            return temp->data;
        }

        if(node1->data == P && node2->data == P || node1->data == Q && node2->data == Q) {
            return node1->data;
        }

        temp = node1;
        node1 = node1->data > P ? node1->left : node1->right;
        node2 = node2->data > Q ? node2->left : node2->right;
    }
    return -1;
}
int main() {
    Node *root = nullptr;
    vector<int> v = {50, 27, 60, 15, 35, 80, 10, 30, 40, 70, 29, 32};
    root = build_bst(root, v);
    cout << LCAinaBST(root, 100, 32) << endl;
    return 0;
}