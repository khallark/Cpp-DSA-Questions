#include <iostream>
#include <unordered_map>
#include "AAAnode.cpp"
using namespace std;
void dfs(Node *root, int k, unordered_map<Node*, Node*> &parents, unordered_map<Node*, bool> &visited) {
    if(root == nullptr || visited[root] == true) return;
    visited[root] = true;
    if(k == 0) cout << root->d << " ";
    dfs(parents[root], k - 1, parents, visited);
    dfs(root->left, k - 1, parents, visited);
    dfs(root->right, k - 1, parents, visited);
}
void printNodesAtDistK(Node *root, int k, int target) {
    Node *TargetNode = nullptr;
    unordered_map<Node*, Node*> parents;
    parents[root] = nullptr;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node *node = q.front();
        if(node->d == target) TargetNode = node;
        q.pop();
        if(node->left) q.push(node->left), parents[node->left] = node;
        if(node->right) q.push(node->right), parents[node->right] = node;
    }
    unordered_map<Node*, bool> visited;
    dfs(TargetNode, k, parents, visited);
}
int main() {
    Node *root = nullptr;
    cout << "INPUT HERE :- ";
    root = build_from_level_order(root);
    // 3 5 1 6 2 0 8 -1 -1 7 4 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "ANS :- ";
    printNodesAtDistK(root, 2, 7);
    return 0;
}