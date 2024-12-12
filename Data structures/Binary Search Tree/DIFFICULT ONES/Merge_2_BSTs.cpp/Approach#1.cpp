#include "C:\Users\ABC\Documents\C++\Data structures\Binary Search Tree\AAABuild_Bst.h"
using namespace std;

void inorder(Node *root, vector<int>& v) {
    if(root == nullptr) {
        return;
    }
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

Node *mergeTwoBSTs(vector<int> bst, int s, int e) {
    if(s > e) {
        return nullptr;
    }

    int mid = s + (e - s) / 2;
    Node *temp = new Node(bst[mid]);

    temp->left = mergeTwoBSTs(bst, s, mid - 1);
    temp->right = mergeTwoBSTs(bst, mid + 1, e);

    return temp;
}

vector<int> merge(Node *root1, Node *root2) {
    vector<int> v1;
    vector<int> v2;

    inorder(root1, v1);
    inorder(root2, v2);

    vector<int> ans(v1.size() + v2.size());
    int i = 0, j = 0;
    int index = 0;

    while(i < v1.size() && j < v2.size()) {
        if(v1[i] < v2[j]) {
            ans[index++] = v1[i++];
        }
        else {
            ans[index++] = v2[j++];
        }
    }

    while(i < v1.size()) {
        ans[index++] = v1[i++];
    }

    while(j < v2.size()) {
        ans[index++] = v2[j++];
    }
    return ans;
}

int main() {
    vector<int> v1 = {5, 3, 6, 2, 4};
    vector<int> v2 = {2, 1, 3, 7, 6};

    Node *root1 = nullptr;
    Node *root2 = nullptr;

    root1 = build_bst(root1, v1);
    root2 = build_bst(root2, v2);
    
    vector<int> ans = merge(root1, root2);

    Node *root3 = mergeTwoBSTs(ans, 0, ans.size() - 1);

    levelOrderTraversal(root3);
    cout << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    return 0;
}