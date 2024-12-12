#include <iostream>
#include "C:\Users\ABC\Documents\C++\Data structures\Binary Tree\AAAnode.h"
vector<int> zigZagTraversal(Node *root) {
    vector<int> ans;

    queue<Node*> normal_flow; // prints the tree in normal level order.
    queue<Node*> reverse_flow; // prints the tree in reversed level order.

    normal_flow.push(root);
    normal_flow.push(nullptr);

    reverse_flow.push(root);
    reverse_flow.push(nullptr);

    int switcher = 0; // helps in switching between 2 queues.

    while(!normal_flow.empty()) {
        Node *temp1 = normal_flow.front();
        normal_flow.pop();

        Node *temp2 = reverse_flow.front();
        reverse_flow.pop();

        if(temp1 == nullptr || temp2 == nullptr) { // if null appears, switch to the other queue.
            switcher ^= 1;
            if(!normal_flow.empty() && !reverse_flow.empty()) {
                normal_flow.push(nullptr);
                reverse_flow.push(nullptr);
            }
        }
        else {
            // if 0, print the elements in normal flow, else 1, print in reversed flow.
            if(switcher == 0)
                ans.push_back(temp1->d);
            else 
                ans.push_back(temp2->d);

            // store in normal order.
            if(temp1->left) 
                normal_flow.push(temp1->left);
            if(temp1->right)
                normal_flow.push(temp1->right);
            
            // store in reversed order.
            if(temp2->right)
                reverse_flow.push(temp2->right);
            if(temp2->left)
                reverse_flow.push(temp2->left);
        }
    }

    return ans;
}
int main() {
    Node *root = build_from_level_order(root);
    // 4 10 -1 5 5 -1 6 7 -1 8 8 -1 8 11 -1 3 4 -1 1 3 -1 8 6 -1 11 11 -1 5 8
    vector<int> ans = zigZagTraversal(root);
    for(auto i: ans) {
        cout << i << " ";
    }
    return 0;
}