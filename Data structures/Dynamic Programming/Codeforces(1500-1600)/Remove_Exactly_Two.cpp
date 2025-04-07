#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
using namespace std;

// unordered_map<int, unordered_map<int, bool>> tree;
// vector<bool> visited;
// int t, n, a, b;

// void bfs(int node) {
//     queue<int> q;
//     q.push(node);
//     visited[node] = true;
//     while(!q.empty()) {
//         int temp = q.front();
//         q.pop();
//         for(auto child : tree[temp]) {
//             if(!visited[child.first]) {
//                 visited[child.first] = true;
//                 q.push(child.first);
//             }
//         }
//     }
// }

// int main() {
//     cin >> t;
//     while(t--) {
//         cin >> n;
//         visited.assign(n + 1, false);
        
//         for(int i = 0; i < n - 1; i++) {
//             cin >> a >> b;
//             tree[a][b];
//             tree[b][a];
//         }

//         int deg = INT_MIN;
//         int node1 = -1;
//         for(auto node : tree) {
//             if(deg < int(tree[node.first].size())) {
//                 deg = int(tree[node.first].size());
//                 node1 = node.first;
//             }
//         }
//         tree.erase(node1);
//         for(auto node : tree) {
//             if(tree[node.first].find(node1) != tree[node.first].end())
//                 tree[node.first].erase(node1);
//         }

//         deg = INT_MIN;
//         int node2 = -1;
//         for(auto node : tree) {
//             if(deg < int(tree[node.first].size())) {
//                 deg = int(tree[node.first].size());
//                 node2 = node.first;
//             }
//         }
//         tree.erase(node2);
//         for(auto node : tree) {
//             if(tree[node.first].find(node2) != tree[node.first].end())
//                 tree[node.first].erase(node2);
//         }

//         int ans = 0;
//         for(auto node : tree) {
//             if(!visited[node.first]) {
//                 bfs(node.first);
//                 ans++;
//             }
//         }

//         cout << ans << endl;
//         tree.clear();
//     }
//     return 0;
// }

int t, n;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        vector<set<int>> tree(n + 1);
        vector<int> degree(n + 1);
        vector<pi> edges(n + 1);
        int a, b;
        for(int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            edges[i] = {a, b};
            tree[a].insert(b);
            tree[b].insert(a);
            degree[a]++; degree[b]++;
        }
        int ans = 0;
        for(auto i : edges) {
            ans = max(ans, degree[i.first] + degree[i.second] - 2); // formula for adjecent nodes
        }
        vector<pi> sortedDegs;
        for(int i = 1; i <= n; i++) {
            sortedDegs.push_back({degree[i], i});
        }
        sort(sortedDegs.begin(), sortedDegs.end(), greater<pi>());
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(tree[sortedDegs[i].second].find(sortedDegs[j].second) == tree[sortedDegs[i].second].end()) {
                    ans = max(ans, sortedDegs[j].first + sortedDegs[i].first - 1); // formula for non-adjacent nodes
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}