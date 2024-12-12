#include <iostream>
#include <queue>
#include <climits>
using namespace std;

const long long M = 1000000007;

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, long long>>> adj(n);
    for(auto i : roads) {
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }
    vector<vector<long long>> dist(n, {LLONG_MAX, 1});
    dist[0] = {0, 1};
    priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        vector<long long> temp = pq.top();
        pq.pop();
        long long distance = temp[0];
        int node = temp[1];
        for(auto i : adj[node]) {
            if(distance + i.second == dist[i.first][0]) {
                dist[i.first][1] = 
                    (0LL + dist[i.first][1] + dist[node][1]) % M;
                continue;
            }
            if(distance + i.second < dist[i.first][0]) {
                dist[i.first][0] = distance + i.second;
                dist[i.first][1] = dist[node][1];
                pq.push({distance + i.second, i.first});
            }
        }
    }
    return dist[n - 1][1] % M;
}

int main() {
    vector<vector<int>> roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    cout << countPaths(7, roads) << endl;
    return 0;
}