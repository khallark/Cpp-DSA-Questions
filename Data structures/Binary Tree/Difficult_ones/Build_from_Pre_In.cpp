#include <iostream>
using namespace std;
struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int x) {
    data = x;
    left = nullptr;
    right = nullptr;
  }
};
Node* buildTree(int in[],int pre[], int n) {
    // Creates the root node of value pre->0.
    Node *root = new Node(pre[0]);

    // n == 1 tells that there's nothing in the left or right of the created node, so just return it without the recursive calls.
    if(n == 1) return root;
    
    // Computation of lengths of the left and the right part to be sliced.
    int left_l; for(left_l = 0; in[left_l] != pre[0]; left_l++) {}
    int right_l = n - left_l - 1;
    cout << left_l << ", "<< right_l << endl;
    int *in_new;
    int *pre_new;

    // Executes only when the array should not be empty.
    if(left_l > 0) { // Making the inorder and preorder arrays ready with the values and pushing them to the next recursive call.
        in_new = new int[left_l];
        pre_new = new int[left_l];
        for(left_l = 0; in[left_l] != pre[0]; left_l++) 
            in_new[left_l] = in[left_l];
        for(int i = 1; i <= left_l; i++)
            pre_new[i - 1] = pre[i];
        root->left = buildTree(in_new, pre_new, left_l);
        delete[] in_new;
        delete[] pre_new;
    }

    // Executes only when the array should not be empty.
    if(right_l > 0) { // Making the inorder and preorder arrays ready with the values and pushing them to the next recursive call.
        in_new = new int[right_l];
        pre_new = new int[right_l];
        for(int i = left_l + 1; i < n; i++) {
            in_new[i - left_l - 1] = in[i];
            pre_new[i - left_l - 1] = pre[i];
        }
        root->right = buildTree(in_new, pre_new, right_l);
        delete[] in_new;
        delete[] pre_new;
    }

    // Returned the node after recursive calls
    return root;
}
void PostOrder_recursive(Node *root) { // Print in order (Left-Right-Current)
    if(root == nullptr) return;
    PostOrder_recursive(root->left); // left
    PostOrder_recursive(root->right); // right
    cout << root->data << " "; // node
}
int main() {
    int in[] = {2, 4, 8, 3, 1, 9, 6};
    int pre[] = {1, 4, 2, 3, 8, 6, 9};
    int n = sizeof(in) / sizeof(int);
    Node *root = buildTree(in, pre, n);
    PostOrder_recursive(root);
    cout << endl;
    return 0;
}