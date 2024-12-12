#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> rank;
    vector<int> size;
    vector<int> parent; 
public:
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
        if(size[u] == size[v])
            parent[v] = u,
            size[u] += size[v];
        else if(size[u] > size[v])
            parent[v] = u,
            size[u] += size[v];
        else
            parent[u] = v;
            size[v] += size[u];
    }
};

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    DisjointSet d(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(isConnected[i][j]) d.unionByRank(i, j);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(d.findParent(i) == i) ans++;
    }
    return ans;
}

int main() {
    vector<vector<int>> adjMat = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    cout << findCircleNum(adjMat) << endl;
    return 0;
}