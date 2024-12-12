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

int main() {
    vector<vector<int>> EdgeList = {
        {0, 1, 5},
        {1, 5, -3},
        {1, 2, -2},
        {5, 3, 1},
        {3, 2, 6},
        {2, 4, 3},
        {3, 4, -2}

        // GRAPH WITH NEGATIVE CYCLE:
        // {0, 1, 3},
        // {1, 2, 2},
        // {2, 3, -5},
        // {3, 1, 1},
        // {3, 4, 2},
        // {4, 5, 4},
        // {5, 3, -3}
    };

    for(auto i : shortest_path_using_bellman_ford(EdgeList, 6, 0)) {
        cout << i << " ";
    }

    return 0;
}