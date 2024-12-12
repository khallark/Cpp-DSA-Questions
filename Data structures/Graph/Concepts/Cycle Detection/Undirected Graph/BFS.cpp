#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

bool bfs(vector<int> adjMat[], int source_node, unordered_map<int, bool>& visited) {
    unordered_map<int, int> parent; // To keep the track of the parent of the nodes
    queue<int> q; // for beadth-first-search

    q.push(source_node);
    visited[source_node] = true;
    parent[source_node] = -1;

    while(!q.empty()) {
        int temp = q.front(); // temp => (current)->node.
        q.pop();

        for(auto neighbour : adjMat[temp]) { // i => (current(list))->node.
            if(!visited[neighbour]) { // if the node is visited for the first time, mark the visited->true, and make the (current)->node as a parent of the (current(list))->node.
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = temp;
            }
            else if(parent[temp] != neighbour) { // if the (current(list))->node is already visited and is not the parent of the (current)->node, then the cycle is present, hence return true.
                return true;
            }
        }
    }
    return false; // if queue is empty, it means that no cycle is found, hence return false.
}

bool isCycle(int V, vector<int> adj[]) {
    unordered_map<int, bool> visited;
    for(int i = 0; i < V; i++) { // special loop for handling graphs with broken components.
        if(!visited[i]) {
            if(bfs(adj, i, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<int> adj[] = {{1}, {0}, {3, 5}, {2, 5}, {8}, {2, 3}, {7, 8, 9}, {6}, {4, 6}, {6}};
    cout << isCycle(9, adj);
    return 0;
}