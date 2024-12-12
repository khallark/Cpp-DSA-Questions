#include <iostream>
#include <map>
#include <vector>
#include "C:\Users\ABC\Documents\C++\Data structures\Binary Tree\AAAnode.h"
using namespace std;

// We need both level and the horizontal distance, as we want every node
vector<int> verticalOrder(Node *root) {
    map<int, map<int, vector<int>>> main_map;
    queue<pair<Node*, pair<int, int>>> q;
    vector<int> ans;

    q.push(make_pair(root, make_pair(0, 0)));
    
    if(root == nullptr) {
        return ans;
    }

    while(!q.empty()) {
        pair<Node*, pair<int, int>> temp_pair = q.front();
        q.pop();

        Node *temp = temp_pair.first;
        int hd = temp_pair.second.first;
        int lvl = temp_pair.second.second;

        main_map[hd][lvl].push_back(temp->d);

        if(temp->left) {
            q.push(make_pair(temp->left, make_pair(hd - 1, lvl + 1)));
        }
        if(temp->right) {
            q.push(make_pair(temp->right, make_pair(hd + 1, lvl + 1)));
        }
    }

    for(auto i : main_map) {
        for(auto j : i.second) {
            for(auto k : j.second) {
                ans.push_back(k);
            }
        }
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