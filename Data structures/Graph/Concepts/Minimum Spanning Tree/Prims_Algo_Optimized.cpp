#include <vector>
#include <iostream>
#include <set>
#include <limits.h>
using namespace std;


// NOTE: Adjecency list is required.
int MinimumSpanningTree(vector<vector<pair<int, int>>> adj, int source_node, int n) {
    vector<int> key(n, INT_MAX); // For tracking the (distances of the nodes).
    set<pair<int, int>> key_util; // For extracting the (node with minimum distance)[Optimized].
    vector<bool> MST(n, false); // For checking if the node is already in the Minimum Spanning Tree of not.
    vector<int> parent(n, -1); // For tracking the parents of nodes.

    key[source_node] = 0; // Initializing the distance of the source node to 0.
    key_util.insert({0, source_node}); // Adding the source node along with its distance

    for(int i = 0; i < n; i++) {
        pair<int, int> p = *key_util.begin();
        auto it = key_util.find(p);
        key_util.erase(it);
        int node_with_minimum_distance = p.second;


        MST[node_with_minimum_distance] = true;


        for(auto neighbours : adj[node_with_minimum_distance]) {
            int neighbours_node = neighbours.first;
            int neighbours_weight = neighbours.second;


            if(MST[neighbours_node] == false && neighbours_weight < key[neighbours_node]) {
                auto it = key_util.find({key[neighbours_node], neighbours_node});
                if(it != key_util.end()) {
                    key_util.erase(it);
                }
                key[neighbours_node] = neighbours_weight;
                parent[neighbours_node] = node_with_minimum_distance;
                key_util.insert({key[neighbours_node], neighbours_node});
            }
        }
    }

    int ans = 0;
    for(auto i : key) {
        ans += i;
    }

    return ans;
}

int main() {
    vector<vector<pair<int, int>>> adj = {
        {{2, 6}},
        {{2, 2}, {3, 5}, {5, 4}},
        {{1, 2}, {5, 9}},
        {{1, 5}, {4, 3}},
        {{3, 3}, {5, 1}},
        {{1, 4}, {2, 9}, {4, 1}}
    };

    int source_node = 0;

    cout << MinimumSpanningTree(adj, source_node, adj.size());

    return 0;
}