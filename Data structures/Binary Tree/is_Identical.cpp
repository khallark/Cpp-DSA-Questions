#include <iostream>
#include "AAAnode.h"
using namespace std;
bool isIdentical(Node *r1, Node *r2) {
    if(r1 == nullptr && r2 == nullptr) {
        return true;
    }
    if(r1 == nullptr && r2 != nullptr || r1 != nullptr && r2 == nullptr) {
        return false;
    }
    if(r1->d != r2->d) {
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    return left && right; 
}
int main() {
    Node *r1;
    Node *r2;
    r1 = build_from_level_order(r1);
    r2 = build_from_level_order(r2);
    cout << endl << isIdentical(r1, r2) << endl;
    return 0;
}