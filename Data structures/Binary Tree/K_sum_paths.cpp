#include <iostream>
#include <vector>
#include "AAAnode.h"
using namespace std;
void solve(Node *root, int k, int &count, vector<int> path) {
    if(root == nullptr) {
        return;
    }

    path.push_back(root->d);

    solve(root->left, k, count, path);
    solve(root->right, k, count, path);

    int sum = 0;
    for(int i = path.size() - 1; i >= 0; i--) {
        sum += path[i];
        if(sum == k) {
            count++;
        }
    }
    path.pop_back();
}
int sumK(Node *root,int k) {
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
}
int main() {
    Node *root = build_from_level_order(root);
    cout << sumK(root, 5);
    return 0;
}