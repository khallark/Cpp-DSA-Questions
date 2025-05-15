#include <iostream>
#include <queue>
using namespace std;

/*

DEFINITION:
A bipartite graph is a graph where its vertices can be
divided into two sets, and every edge connects a vertex
from one set to a vertex from the other set.

HOW TO IDENTIFY:
If we take a BIPARTITE GRAPH and start coloring its nodes
with two different colors exchangingly, then EVERY TWO
ADJACENT NODES WILL HAVE DIFFERENT COLOR.

*/

bool dfs(vector<vector<int>>& adj, vector<int>& color, int node, int colors) {
    color[node] = colors;
    bool notStop = true;
    for(auto i : adj[node]) {
        if(!notStop) break;
        if(color[i] == -1) {
            notStop = dfs(adj, color, i, !colors);
        } else if(color[node] == color[i]) {
            return false;
        }
    }
    return notStop;
}
bool isBipartiteDFS(vector<vector<int>>& edges, int n) {
    vector<vector<int>> adj(n + 1);
    for(auto i : edges) {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<int> color(n + 1, -1);
    return dfs(adj, color, 1, 0);
}

int main() {
    vector<vector<int>> notBipartite = {{1, 2}, {2, 3}, {2, 6}, {3, 4}, {6, 5}, {4, 5}, {4, 7}, {7, 8}};
    vector<vector<int>> bipartite = {{1, 2}, {2, 3}, {2, 5}, {3, 4}, {5, 4}, {4, 6}};
    cout << isBipartiteDFS(notBipartite, 8) << endl << isBipartiteDFS(bipartite, 6);
    return 0;
}