#include <iostream>
#include <set>
#include <vector>
#include <limits.h>
using namespace std;
int n, m;
vector<vector<pair<int, int>>> adj;
int source_node = 1;


vector<long long> shortest_path_using_dijkstra() {
    set<pair<long long, int>> s;
    vector<long long> ans(n + 1, LLONG_MAX);
    
    s.insert({0, source_node});
    ans[source_node] = 0;
    
    while(!s.empty()) {
        pair<int, int> node = *s.begin();

        // current popped set (node value) and (it's total distance from the source node so far)
        int current_popped_node = node.second;

        s.erase(s.begin());

        for(auto neighbours : adj[current_popped_node]) {

            // current (neighbour node) and (it's distance from the current (set popped node))
            int neighbour_distance = neighbours.second;
            int neighbour_node = neighbours.first;


            if(ans[current_popped_node] + (long long)neighbour_distance < ans[neighbour_node]) {
                if(s.find({ans[neighbour_node], neighbour_node}) != s.end()) {
                    s.erase({ans[neighbour_node], neighbour_node});
                }

                ans[neighbour_node] = ans[current_popped_node] + (long long)neighbour_distance;
                s.insert({ans[neighbour_node], neighbour_node});
            }
        }
    }

    return ans;
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        adj[n1].push_back({n2, w});
    }
    vector<long long> ans = shortest_path_using_dijkstra();
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}