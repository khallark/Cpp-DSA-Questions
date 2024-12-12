#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> shortest_Path(vector<vector<int>> adj, int source, int destination) {
    unordered_map<int, int> parent;
    unordered_map<int, bool> visited;
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(auto neighbour : adj[front]) {
            if(!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }

    vector<int> ans;
    ans.push_back(destination);
    int node = destination;
    while(node != source) {
        ans.push_back(parent[node]);
        node = parent[node];
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    vector<vector<int>> adj = {{1}, {0, 2, 3}, {1, 6, 7}, {1, 4, 5}, {3, 5}, {3, 4}, {2, 7}, {2, 6}};
    for(auto i : shortest_Path(adj, 6, 0)) {
        cout << i << " ";
    }
    return 0;
}