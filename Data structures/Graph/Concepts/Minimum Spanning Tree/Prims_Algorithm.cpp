#include <vector>
#include <iostream>
#include <unordered_map>
#include <limits.h>
using namespace std;

int spanningTree(vector<vector<pair<int, int>>> adj, int source_node, int n) {
    vector<int> key(n, INT_MAX);
    vector<bool> MST(n, false);
    vector<int> parent(n, -1);

    key[source_node] = 0;

    for(int i = 0; i < n; i++) {
        // Step 1 : Find out the (node with minimum distance), so far.
        int minimum_dist_node = INT_MIN;
        int minimum_dist = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(MST[i] == false && key[i] < minimum_dist) {
                minimum_dist = key[i];
                minimum_dist_node = i;
            }
        }

        // Step 2: Mark the (node with minimum distance) in the Minimum Spannig tree as TRUE.
        MST[minimum_dist_node] = true;

        // Step 3: Traverse through the neighbours of the (node with minimum distance).
        for(auto neighbours : adj[minimum_dist_node]) {
            int neighbours_node = neighbours.first;
            int neighbours_weight = neighbours.second;

            // If the weights of the neighbours is less than their previously marked weight, then modify their weight and mark its parents as the (node with minimum distance).
            if(neighbours_weight < key[neighbours_node]) {
                key[neighbours_node] = neighbours_weight;
                parent[neighbours_node] = minimum_dist_node;
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
        {{1, 2}, {3, 6}},
        {{0, 2}, {2, 3}, {3, 8}, {4, 5}},
        {{1, 3}, {4, 7}},
        {{0, 6}, {1, 8}},
        {{1, 5}, {2, 7}}
    };

    int source_node = 0;

    cout << spanningTree(adj, source_node, adj.size());

    return 0;
}