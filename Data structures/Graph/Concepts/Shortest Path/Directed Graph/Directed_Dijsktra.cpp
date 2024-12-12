#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

pair<vector<vector<int>>, vector<int>> shortest_path_using_dijkstra(vector<vector<pair<int, int>>> adj, int n, int source_node) {
    set<pair<int, int>> s;
    vector<int> parent(n, -1);
    vector<int> ans(n, INT_MAX);
    vector<vector<int>> paths;
    
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


            if(ans[current_popped_node] + neighbour_distance < ans[neighbour_node]) {
                if(s.find({ans[neighbour_node], neighbour_node}) != s.end()) {
                    s.erase({ans[neighbour_node], neighbour_node});
                }

                ans[neighbour_node] = ans[current_popped_node] + neighbour_distance;
                parent[neighbour_node] = current_popped_node;
                s.insert({ans[neighbour_node], neighbour_node});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        int node = parent[i];
        vector<int> path;
        path.push_back(i);
        while(node != -1) {
            path.push_back(node);
            node = parent[node];
        }
        reverse(path.begin(), path.end());
        paths.push_back(path);
    }

    return make_pair(paths, ans);
}

int main() {
    vector<vector<pair<int, int>>> adj = {
        {{2, 3}, {5, 2}},
        {{3, 1}, {4, 2}, {5, 6}, {6, 2}},
        {{0, 3}, {3, 4}, {4, 1}, {5, 2}},
        {{1, 1}, {2, 4}},
        {{1, 2}, {2, 1}, {5, 3}},
        {{0, 2}, {1, 6}, {2, 2}, {4, 3}, {6, 5}},
        {{1, 2}, {5, 5}}
    };

    int n = adj.size();

    int source_node = 0;

    pair<vector<vector<int>>, vector<int>> p = shortest_path_using_dijkstra(adj, n, source_node);

    cout << "Distances :" << endl;
    for(auto i : p.second) {
        cout << char('A' + i) << " : "; 
        if(i == INT_MAX) {
            cout << "INF ";
        }
        else {
            cout << i << " ";
        }
        cout << endl;
    }

    cout << endl << "Paths :" << endl;
    for(auto i : p.first) {
        cout << "-> ";
        for(auto j : i) {
            cout << char('A' + j) << " ";
        }
        cout << endl;
    }

    return 0;
}