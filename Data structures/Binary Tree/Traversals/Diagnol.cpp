#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include "C:\Users\ABC\Documents\C++\Data structures\Binary Tree\AAAnode.h"
using namespace std;

void solve(Node *root, map<int, map<int, vector<int>>>& m, int level, int slope) {
    if(root == nullptr) {
        return;
    }

    m[slope][level].push_back(root->d);
    
    solve(root->left, m, level + 1, slope + 1);
    solve(root->right, m, level + 1, slope);
}
vector<int> diagonal(Node *root) {
   vector<int> ans;
   map<int, map<int, vector<int>>> m;
   solve(root, m, 0, 0);
   for(auto i : m) {
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
    // 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
    vector<int> ans = diagonal(root);
    cout << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    return 0;
}