#include <iostream>
#include <queue>
#include <climits>
#include <set>
using namespace std;

struct comp {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]);
    }
};
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);
    for(auto i : flights) {
        adj[i[0]].push_back({i[1], i[2]});
    }
    vector<int> dist(n, INT_MAX);
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    dist[src] = 0;
    pq.push({0, 0, src});
    while(!pq.empty()) {
        vector<int> temp = pq.top();
        pq.pop();
        if(temp[0] == k + 1 && temp[2] != dst) continue;
        for(auto i : adj[temp[2]]) {
            if(temp[1] + i.second < dist[i.first]) {
                dist[i.first] = temp[1] + i.second;
                pq.push({temp[0] + 1, dist[i.first], i.first});
            }
        }
    }
    return dist[dst] != INT_MAX ? dist[dst] : -1;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0,1,5},{1,2,5},{0,3,2},{3,1,2},{1,4,1},{4,2,1}};
    int src = 0, dst = 2, k = 2;
    cout << findCheapestPrice(n, edges, src, dst, k);
    return 0;
}