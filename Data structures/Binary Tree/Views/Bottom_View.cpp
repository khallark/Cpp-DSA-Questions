#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include "C:\Users\ABC\Documents\C++\Data structures\Binary Tree\AAAnode.h"
using namespace std;

// We only need level, not the horizontal distance
vector<int> verticalOrder(Node *root) {
    map<int, int> main_map;
    queue<pair<Node*, int>> q;
    vector<int> ans;

    q.push(make_pair(root, 0));
    
    if(root == nullptr) {
        return ans;
    }

    while(!q.empty()) {
        pair<Node*, int> temp_pair = q.front();
        q.pop();

        Node *temp = temp_pair.first;
        int hd = temp_pair.second;

        main_map[hd] = temp->d;

        if(temp->left) {
            q.push(make_pair(temp->left, hd - 1));
        }
        if(temp->right) {
            q.push(make_pair(temp->right, hd + 1));
        }
    }

    for(auto i : main_map) {
        ans.push_back(i.second);
    }
    
    return ans;
}
int main() {
    Node *root = build_from_level_order(root);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
    vector<int> ans = verticalOrder(root);
    cout << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    return 0;
}