#include <iostream>
#include "AAAnode.h"
using namespace std;
pair<int, int> solve(Node *root) {
    if(root == nullptr) {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    int sum = 0;
    if(left.second != right.second) {
        sum = (left.second > right.second ? left.first : right.first) + root->d;
    }
    else {
        sum = (left.first > right.first ? left.first : right.first) + root->d;
    }
    int height = max(left.second, right.second) + 1;

    pair<int, int> ret;
    ret.first = sum;
    ret.second = height;

    return ret;
}
int sumOfLongRootToLeafPath(Node *root) {
    return solve(root).first;
}
int main() {
    Node *root = build_from_level_order(root);
    cout << endl << endl << sumOfLongRootToLeafPath(root) << endl;
}