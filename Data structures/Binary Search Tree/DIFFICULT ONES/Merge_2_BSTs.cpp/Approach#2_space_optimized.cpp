#include "C:\Users\ABC\Documents\C++\Data structures\Binary Search Tree\AAABuild_Bst.h"
using namespace std;

// Converts the 2 BSTs into Doubly-LLs.
pair<Node*, Node*> solve(Node *root) {
    // Base case
    if(root == nullptr) {
        pair<Node*, Node*> p = make_pair(nullptr, nullptr);
        return p;
    }

    pair<Node*, Node*> left = solve(root->left);
    pair<Node*, Node*> right = solve(root->right);

    root->left = left.second;
    if(left.second) left.second->right = root;

    root->right = right.first;
    if(right.second) right.first->left = root;

    pair<Node*, Node*> ret_pair;
    ret_pair.first = left.first ? left.first : root;
    ret_pair.second = right.second ? right.second : root;

    return ret_pair;
}
Node *BstToDLL(Node *root) {
    return solve(root).first;
}

// Merges the 2 sorted DLLs in a sorted manner.
Node *merge_DLLs(Node *root1, Node *root2) {
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    while(root1 && root2) {
        if(root1->data < root2->data) {
            dummy->right = root1;
            root1->left = dummy;
            root1 = root1->right;
            dummy = dummy->right;
        }
        else {
            dummy->right = root2;
            root2->left = dummy;
            root2 = root2->right;
            dummy = dummy->right;
        }
    }
    while(root1) {
        dummy->right = root1;
        root1->left = dummy;
        root1 = root1->right;
        dummy = dummy->right;
    }
    while(root2) {
        dummy->right = root2;
        root2->left = dummy;
        root2 = root2->right;
        dummy = dummy->right;
    }

    Node *ans = temp->right;
    delete temp;
    ans->left = nullptr;
    return ans;
}

// Converts a DLL into a BST(Balanced).
Node *DLLToBst(Node *head) {
    if(head == nullptr) {
        return nullptr;
    }
    if(head->left == nullptr && head->right == nullptr) {
        return head;
    }

    Node *slow = head;
    Node* fast = head;
    while(fast && fast->right) {
        slow = slow->right;
        fast = fast->right->right;
    }

    if(slow->left) slow->left->right = nullptr;
    if(slow->right) slow->right->left = nullptr;

    slow->left = DLLToBst(head);
    slow->right = DLLToBst(slow->right);

    return slow;
}

// Merges two BSTs in a balanced manner.
Node *merge(Node *root1, Node *root2) {
    root1 = BstToDLL(root1);
    root2 = BstToDLL(root2);
    Node *root3 = merge_DLLs(root1, root2);
    root3 = DLLToBst(root3);
    return root3;
}
int main() {
    Node *root1 = nullptr;
    Node *root2 = nullptr;
    vector<int> v1 = {6, 7, 8, 9, 10};
    vector<int> v2 = {1, 2, 3, 4, 5};
    root1 = build_bst(root1, v1);
    root2 = build_bst(root2, v2);
    levelOrderTraversal(root1);
    cout << endl;
    levelOrderTraversal(root2);
    cout << endl;
    Node *root3 = merge(root1, root2);
    levelOrderTraversal(root3);
    return 0;
}