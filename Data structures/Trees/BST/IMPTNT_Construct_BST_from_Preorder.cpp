#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include "AAAnode.cpp"
using namespace std;


// O(n^2)
Node *solve1(vector<int> &preorder, int i, int j) {
    if(i > j) return nullptr;
    Node *root = new Node(preorder[i]);
    int k;
    for(k = i + 1; k <= j; k++) {
        if(preorder[k] > preorder[i]) {
            k--;
            break;
        }
    }
    if(k == j + 1) k--;
    root->left = solve1(preorder, i + 1, k);
    root->right = solve1(preorder, k + 1, j);
    return root;
}
Node *construct1(vector<int> &preorder) {
    return solve1(preorder, 0, preorder.size() - 1);
}



// O(nlogn)
Node *solve2(vector<int> &preorder, unordered_map<int, int> &indexes, int i1, int j1, int i2, int j2) {
    if(i1 > j1) return nullptr;
    int k = indexes[preorder[i2]];
    Node *root = new Node(preorder[i2]);
    root->left = solve2(preorder, indexes, i1, k - 1, i2 + 1, i2 + (k - i1));
    root->right = solve2(preorder, indexes, k + 1, j1, j2 - (j1 - k) + 1, j2);
    return root;
}

Node *construct2(vector<int> &preorder) {
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());
    unordered_map<int, int> indexes;
    int count = 0;
    for(auto i : inorder) indexes[i] = count++;
    Node *root = solve2(preorder, indexes, 0, inorder.size() - 1, 0, preorder.size() - 1);
    return root;
}



// O(n)
Node *solve3(vector<int> &preorder, int &ind, int upperBound) {
    if(ind == preorder.size()) return nullptr;
    if(preorder[ind] >= upperBound) return nullptr;
    int index = ind;
    ind++;
    Node *root = new Node(preorder[index]);
    root->left = solve3(preorder, ind, preorder[index]);
    root->right = solve3(preorder, ind, upperBound);
    return root;
}
Node *construct3(vector<int> &preorder) {
    int ind = 0;
    return solve3(preorder, ind, INT_MAX);
}


void inorder(Node *root) {
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->d << " ";
    inorder(root->right);
}
int main() {
    vector<int> preorder = {7, 2, 1, 5, 3, 4, 6, 9, 8, 10};
    Node *root = construct3(preorder);
    inorder(root);
    return 0;
}