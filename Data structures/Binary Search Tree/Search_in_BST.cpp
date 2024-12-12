#include "AAABuild_Bst.h"
using namespace std;
bool search_in_bst(Node *root, int val) {
    Node *ans = root;
    while(ans) {
        if(ans->data == val)
            return true;

        else if(ans->data > val)
            ans = ans->left;

        else
            ans = ans->right;
    }
    return false;
}
int main() {
    vector<int> v = {5, 4, 6, 3, 7, 2, 8, 1, 9};
    Node *root = nullptr;
    root = build_bst(root, v);
    cout << search_in_bst(root, 0) << endl;
    return 0;
}