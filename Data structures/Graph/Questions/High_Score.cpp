#include <iostream>
#include <limits.h>
#include <vector>
#define ll long long
using namespace std;
int n, m;
vector<vector<int>> edgeList;
int source = 1;

vector<ll> longest_path_using_bellman_ford() {
    vector<ll> dist(n + 1, LLONG_MAX);
    dist[source] = 0;

    // first (N - 1) relaxations for finding the Shortest Distances.
    for(int i = 0; i < n - 1; i++) {
        for(auto j : edgeList) {
            int u = j[0];
            int v = j[1];
            ll wt = j[2];

            // Relaxation Formula (Similar to the Dijkstra's Algo).
            if(dist[u] < LLONG_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // second Nth relaxation for finding the Negative Cycle.
    // In this relaxation, if the distances modify further, there is a Negative Cycle.
    for(auto j : edgeList) {
        int u = j[0];
        int v = j[1];
        ll wt = j[2];

        if(dist[u] < LLONG_MAX && dist[u] + wt < dist[v]) {
            return vector<ll>(n, -1);
        }
    }

    return dist;
}

int main() {
    cin >> n >> m;
    edgeList.resize(m);
    for(auto& i : edgeList) {
        int a, b, w;
        cin >> a >> b >> w;
        w = 0 - w;
        i = {a, b, w};
    }
    cout << 0 - longest_path_using_bellman_ford()[n] << endl;
    return 0;
}