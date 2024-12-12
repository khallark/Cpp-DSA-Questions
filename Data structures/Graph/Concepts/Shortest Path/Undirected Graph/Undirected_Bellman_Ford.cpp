#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

vector<int> shortest_path_using_bellman_ford(vector<vector<int>> EdgeList, int V, int source) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    // first (N - 1) relaxations for finding the Shortest Distances.
    for(int i = 0; i < V - 1; i++) {
        for(auto j : EdgeList) {
            int u = j[0];
            int v = j[1];
            int wt = j[2];

            // Relaxation Formula (Similar to the Dijkstra's Algo).
            if(dist[u] < INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // second Nth relaxation for finding the Negative Cycle.
    // In this relaxation, if the distances modify further, there is a Negative Cycle.
    for(auto j : EdgeList) {
        int u = j[0];
        int v = j[1];
        int wt = j[2];

        if(dist[u] < INT_MAX && dist[u] + wt < dist[v]) {
            cout << "Negative Cycle Detected." << endl;
            return vector<int>(V, -1);
        }
    }

    return dist;
}

vector<vector<int>> Weighted_edges(vector<vector<pair<int, int>>>& adj) {
    vector<vector<int>> ans;
    for(int i = 0; i < adj.size(); i++) {
        for(auto j : adj[i]) {
            ans.push_back({i, j.first, j.second});
        }
    }
    return ans;
}

int main() {
    vector<vector<pair<int, int>>> adj = {
            {{1, 7}, {2, 1}, {3, 2}},
            {{0, 7}, {2, 3}, {3, 5}, {4, 1}},
            {{0, 1}, {1, 3}},
            {{0, 2}, {1, 5}, {4, 7}},
            {{1, 1}, {3, 7}}
        };

    for(auto i : shortest_path_using_bellman_ford(Weighted_edges(adj), 5, 0)) {
            cout << i << " ";
    }

    return 0;
}