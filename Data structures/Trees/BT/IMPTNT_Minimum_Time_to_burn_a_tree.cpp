#include <iostream>
#include <unordered_map>
#include "AAAnode.cpp"
using namespace std;
int MinTimeToBurn(Node *root, int target) {
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
    q.push(TargetNode);
    q.push(nullptr);
    visited[TargetNode] = true;
    int time = 0;
    while(!q.empty()) {
        Node *node = q.front();
        visited[node] = true;
        q.pop();

        if(parents[node] && !visited[parents[node]])
            q.push(parents[node]);
        if(parents[node->left] && !visited[node->left])
            q.push(node->left);
        if(parents[node->right] && !visited[node->right])
            q.push(node->right);

        if(q.front() == nullptr) {
            q.pop();
            if(!q.empty()) q.push(nullptr), time++;
        }
    }

    return time;
}
int main() {
    Node *root = nullptr;
    cout << "INPUT HERE :- ";
    root = build_from_level_order(root);
    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "ANS :- " << MinTimeToBurn(root, 5);
    return 0;
}