#include <iostream>
#include <queue>
using namespace std;

/*

DEFINITION:
A bipartite graph is a graph where its vertices can be
divided into two sets, and every edge connects a vertex
in one set to a vertex in the other set.

HOW TO IDENTIFY:
If we take a BIPARTITE GRAPH and start coloring its nodes
with two different colors exchangingly, then EVERY TWO
ADJACENT NODES WILL HAVE DIFFERENT COLOR.

*/


bool isBipartiteBFS(vector<vector<int>>& edges, int n) {
    vector<vector<int>> adj(n + 1);
    for(auto i : edges) {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<int> color(n + 1, -1);
    queue<int> q;
    q.push(1);
    color[1] = 0;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto i : adj[curr]) {
            if(color[i] == -1) {
                color[i] = !color[curr];
                q.push(i);
            } else if(color[i] == color[curr]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> notBipartite = {{1, 2}, {2, 3}, {2, 6}, {3, 4}, {6, 5}, {4, 5}, {4, 7}, {7, 8}};
    vector<vector<int>> bipartite = {{1, 2}, {2, 3}, {2, 5}, {3, 4}, {5, 4}, {4, 6}};
    cout << isBipartiteBFS(notBipartite, 8) << endl << isBipartiteBFS(bipartite, 6);
    return 0;
}