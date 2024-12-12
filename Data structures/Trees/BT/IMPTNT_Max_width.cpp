#include <iostream>
#include <queue>
#include "AAAnode.cpp"
using namespace std;
typedef Node TreeNode;
int widthOfBinaryTree(TreeNode* root) {
    TreeNode *partitioner = new Node(1);

    queue<pair<TreeNode*, int>> q;

    int min_lvl_indx = 0, max_lvl_ind = 0;
    int max_width = 1;

    q.push({root, 0});
    q.push({partitioner, 0});

    while(!q.empty()) {
        pair<TreeNode*, int> temp = q.front();
        q.pop();
        TreeNode *node = temp.first;
        int index = temp.second;

        if(node->left) q.push({node->left, 2 * (index - min_lvl_indx) + 1}); // 2 * (i - min) + 1;
        if(node->right) q.push({node->right, 2 * (index - min_lvl_indx) + 2}); // 2 * (i - min) + 2;

        if(q.front() == make_pair(partitioner, 0)) {
            max_lvl_ind = index;
            cout << "(" << max_lvl_ind << " - " << min_lvl_indx << ") + 1 = " << max_lvl_ind - min_lvl_indx + 1 << endl; 
            max_width = max(max_width, max_lvl_ind - min_lvl_indx + 1);
            q.pop();
            if(!q.empty()) {
                q.push({partitioner, 0});
                min_lvl_indx = q.front().second;
            }
        }
    }

    return max_width;
}
int main() {
    Node *root = nullptr;
    cout << "INPUT - ";
    root = build_from_level_order(root);
    // 1 1 1 1 1 1 1 -1 -1 -1 1 -1 -1 -1 -1 2 2 2 2 2 2 2 -1 2 -1 -1 2 -1 2 -1 -1 -1 -1 -1 -1 -1 -1
    // 1 1 1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 1 -1 -1 1 1 -1 1 -1 1 -1 1 -1 1 -1 -1 -1 1 -1 -1 -1
    cout << widthOfBinaryTree(root);
    return 0;
}