#include <iostream>
#include "AAAnode.h"
using namespace std;
bool mirror_or_not(Node *root1, Node *root2) {
    if(root1 == nullptr && root2 == nullptr) return true;
    if(root1 != nullptr && root2 == nullptr || root1 == nullptr && root2 != nullptr) return false;
    if(root1->d != root2->d) return false;
    return mirror_or_not(root1->left, root2->right) && mirror_or_not(root1->right, root2->left);
}
int main() {
    Node *root1 = build_from_level_order(root1);
    cout << endl;
    Node *root2 = build_from_level_order(root2);
    cout << endl << mirror_or_not(root1, root2) << endl;
    return 0;
}