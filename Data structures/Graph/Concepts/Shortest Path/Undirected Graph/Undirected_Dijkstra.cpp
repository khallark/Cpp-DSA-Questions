#include <iostream>
#include <set>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> shortest_path_using_dijkstra(vector<vector<pair<int, int>>> adj, int n, int source_node) {
    set<pair<int, int>> s;
    vector<int> ans(n, INT_MAX);
    
    s.insert({0, source_node});
    ans[source_node] = 0;
    
    while(!s.empty()) {
        pair<int, int> node = *s.begin();

        // current popped set (node value) and (it's total distance from the source node so far)
        int current_distance = node.first;
        int current_popped_node = node.second;

        s.erase(s.begin());

        for(auto neighbours : adj[current_popped_node]) {

            // current (neighbour node) and (it's distance from the current (set popped node))
            int neighbour_distance = neighbours.second;
            int neighbour_node = neighbours.first;


            if(current_distance + neighbour_distance < ans[neighbour_node]) {
                if(s.find({ans[neighbour_node], neighbour_node}) != s.end()) {
                    s.erase({ans[neighbour_node], neighbour_node});
                }

                ans[neighbour_node] = current_distance + neighbour_distance;
                s.insert({ans[neighbour_node], neighbour_node});
            }
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

    int n = adj.size();

    int source_node = 0;

    for(auto i : shortest_path_using_dijkstra(adj, n, source_node)) {
        if(i == INT_MAX) {
            cout << "INF ";
        }
        else {
            cout << i << " ";
        }
    }

    return 0;
}