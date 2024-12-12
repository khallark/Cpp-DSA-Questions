#include <iostream>
#include <map>
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

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    DisjointSet d(n);
    map<string, int> m;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < accounts[i].size(); j++) {
            if(m[accounts[i][j]] == 0) {
                m[accounts[i][j]] = i + 1;
            }else {
                d.unionByRank(m[accounts[i][j]], i + 1);
            }
        }
    }
    vector<vector<string>> merged(n);
    for(int i = 1; i <= n; i++) {
        if(d.findParent(i) == i) {
            merged[i - 1].push_back({accounts[i - 1][0]});
        }
    }
    for(auto i : m) {
        merged[d.findParent(i.second) - 1].push_back(i.first);
    }
    vector<vector<string>> ans;
    for(auto i : merged) {
        if(!i.empty()) ans.push_back(i);
    }
    return ans;
}

int main() {
    vector<vector<string>> accounts = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };
    cout << endl;
    for(auto i : accountsMerge(accounts)) {
        for(auto j : i) {
            cout << j << ", ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}