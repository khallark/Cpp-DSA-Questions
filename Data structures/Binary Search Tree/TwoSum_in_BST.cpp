#include "AAABuild_Bst.h"
using namespace std;
void inorder(Node *root, vector<int>& v) {
    if(root == nullptr) {
        return;
    }
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}
int isPairPresent(Node *root, int target) {
    vector<int> v;
    inorder(root, v);
    int i = 0, j = v.size() - 1;   
    while(i < j) {
        if(v[i] + v[j] == target) {
            return true;
        }
        else if(v[i] + v[j] < target) {
            i++;
        }
        else {
            j--;
        }
    }
    return false;
}
int main() {
    vector<int> v = {10, 6, 12, 2, 8, 11, 15};
    Node *root = nullptr;
    root = build_bst(root, v);
    cout << isPairPresent(root, 15) << endl;
    return 0;
}