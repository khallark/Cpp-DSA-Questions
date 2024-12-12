#include <iostream>
#include <set>
#include <vector>
#include <limits.h>
#define ll long long
using namespace std;
int n, m, q;
vector<vector<int>> queries;
vector<vector<pair<int, int>>> adj;
vector<vector<ll>> ans;

void shortest_path_using_dijkstra(int source_node) {
    set<pair<ll, int>> s;
    
    s.insert({0, source_node});
    ans[source_node][source_node] = 0;
    
    while(!s.empty()) {
        pair<int, int> node = *s.begin();

        // current popped set (node value) and (it's total distance from the source node so far)
        int current_popped_node = node.second;

        s.erase(s.begin());

        for(auto neighbours : adj[current_popped_node]) {

            // current (neighbour node) and (it's distance from the current (set popped node))
            int neighbour_distance = neighbours.second;
            int neighbour_node = neighbours.first;


            if(ans[source_node][current_popped_node] + (ll)neighbour_distance < ans[source_node][neighbour_node]) {
                if(s.find({ans[source_node][neighbour_node], neighbour_node}) != s.end()) {
                    s.erase({ans[source_node][neighbour_node], neighbour_node});
                }

                ans[source_node][neighbour_node] = ans[source_node][current_popped_node] + (ll)neighbour_distance;
                s.insert({ans[source_node][neighbour_node], neighbour_node});
            }
        }
    }
}

int main() {
    cin >> n >> m >> q;
    ans = vector<vector<ll>>(n + 1, vector<ll>(n + 1, LLONG_MAX));
    adj.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        adj[n1].push_back({n2, w});
        adj[n2].push_back({n1, w});
    }
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        queries.push_back({a, b});
    }
    for(int i = 1; i <= n; i++) {
        shortest_path_using_dijkstra(i);
    }
    for(auto i : queries) {
        if(ans[i[0]][i[1]] == LLONG_MAX) cout << -1 << endl;
        else cout << ans[i[0]][i[1]] << endl;
    }
    return 0;
}