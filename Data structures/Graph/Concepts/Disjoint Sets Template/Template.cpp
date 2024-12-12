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
        if(size[u] >= size[v])
            parent[v] = u,
            size[u] += size[v];
        else
            parent[u] = v,
            size[v] += size[u];
    }
};

int main() {
    int n = 7;
    DisjointSet d(n);
    d.unionByRank(1, 2);
    d.unionByRank(2, 3);
    d.unionByRank(4, 5);
    d.unionByRank(6, 7);
    d.unionByRank(5, 6);
    d.unionByRank(3, 7);
    cout << (d.findParent(3) == d.findParent(7));
    return 0;
}