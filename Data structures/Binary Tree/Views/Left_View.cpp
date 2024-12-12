#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include "C:\Users\ABC\Documents\C++\Data structures\Binary Tree\AAAnode.h"
using namespace std;

// We only need level, not the horizontal distance
vector<int> leftView(Node *root) {
    queue<pair<Node*, int>> q;
    map<int, bool> level;
    vector<int> ans;
    
    if(root == nullptr) {
        return ans;
    }

    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<Node*, int> temp_pair = q.front();
        q.pop();

        Node *temp = temp_pair.first;
        int lvl = temp_pair.second;

        if(level[lvl] == false) {
            ans.push_back(temp->d);
            level[lvl] = true;
        }

        if(temp->left) {
            q.push(make_pair(temp->left, lvl + 1));
        }
        if(temp->right) {
            q.push(make_pair(temp->right, lvl + 1));
        }
    }
    
    return ans;
}

void solve(Node *root, vector<int>& ans, int level) {
    if(root == nullptr) {
        return;
    }

    if(level == ans.size()) { // entered new level
        ans.push_back(root->d);
    }
    
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}
vector<int> leftView2(Node *root) {
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main() {
    Node *root = build_from_level_order(root);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
    vector<int> ans = leftView2(root);
    cout << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    return 0;
}