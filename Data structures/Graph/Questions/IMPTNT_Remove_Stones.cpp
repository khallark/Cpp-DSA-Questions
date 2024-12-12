#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
public:
    vector<int> rank;
    vector<int> size;
    vector<int> parent; 
    DisjointSet(int n) {
        rank.resize(n + 1);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int n) {
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }

    void unionByRank(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        if(u == v) return;
        if(rank[u] == rank[v])
            parent[v] = u,
            rank[u]++;
        else if(rank[u] > rank[v])
            parent[v] = u;
        else
            parent[u] = v;
    }

    void unionBySize(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        if(u == v) return;
        if(size[u] >= size[v])
            parent[v] = u,
            size[u] += size[v];
        else
            parent[u] = v,
            size[v] += size[u];
    }
};
int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    DisjointSet d(n);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int i1 = stones[i][0], j1 = stones[i][1];
            int i2 = stones[j][0], j2 = stones[j][1];
            if(i1 == i2 || j1 == j2) {
                d.unionBySize(i, j);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(d.findParent(i) == i) ans += d.size[i] - 1;
    }
    return ans;
}

int main() {
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout << removeStones(stones);
    return 0;
}