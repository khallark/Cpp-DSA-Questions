#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef struct TreeNode Node;
vector<vector<pair<bool, vector<Node*>>>> dp;

pair<bool, vector<Node*>> f(int l, int r) {
    if(l > r) {
        return dp[l][r] = {true, {nullptr}};
    }
    if(dp[l][r].first) return dp[l][r];
    vector<Node*> ans;
    for(int m = l; m <= r; m++) {
        vector<Node*> left = f(l, m - 1).second;
        vector<Node*> right = f(m + 1, r).second;
        for(auto i : left) {
            for(auto j : right) {
                Node *node = new Node(m);
                node->left = i;
                node->right = j;
                ans.push_back(node);
            }
        }
    }
    return dp[l][r] = {true, ans};
}

vector<Node*> generateTrees(int n) {
    dp.resize(n + 2, vector<pair<bool, vector<Node*>>>(n + 2, {false, vector<Node*>()}));
    return f(1, n).second;
}

int main() {
    vector<Node*> ans = generateTrees(8);
    cout << "OK";
    return 0;
}