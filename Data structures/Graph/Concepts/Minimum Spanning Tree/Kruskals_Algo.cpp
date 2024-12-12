#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comparator(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

void PrepareParentSet(vector<int> &parent) {
    for(int i = 0; i < parent.size(); i++) {
        parent[i] = i;
    }
}

int find_parent(vector<int> &parent, int node) {
    if(parent[node] == node) {
        return node;
    }
    return parent[node] = find_parent(parent, parent[node]);
}

void _union_(int u, int v, vector<int> &rank, vector<int> &parent) {

    int parent_u = find_parent(parent, u);
    int parent_v = find_parent(parent, v);
    int rank_u = rank[parent_u];
    int rank_v = rank[parent_v];

    if(rank_u > rank_v) {
        parent[parent_v] = parent_u;
    }
    else if(rank_v > rank_u) {
        parent[parent_u] = parent_v;
    }
    else {
        parent[parent_v] = parent_u;
        rank[parent_u] += 1;
    }
}

// Doesn't require adjecency list, requires, edge info only.
int spanningTree(vector<vector<int>> edges, int n) {
    sort(edges.begin(), edges.end(), comparator);

    int total_minimum_weight = 0;
    vector<int> parent(n);
    vector<int> rank(n, 0);
    PrepareParentSet(parent);

    for(auto i : edges) {
        int u = find_parent(parent, i[0]);
        int v = find_parent(parent, i[1]);
        int w = i[2];

        if(u != v) {
            total_minimum_weight += w;
            _union_(u, v, rank, parent);
        }
    }

    return total_minimum_weight;
}
int main() {
    vector<vector<int>> edges = {
             /*u, v*/        /*weights*/
        {      5, 4,   /*|*/     10      },
        {      0, 7,   /*|*/     8       },
        {      2, 3,   /*|*/     7       },
        {      7, 6,   /*|*/     1       },
        {      6, 5,   /*|*/     2       },
        {      1, 7,   /*|*/     11      },
        {      8, 6,   /*|*/     6       },
        {      3, 4,   /*|*/     9       },
        {      1, 2,   /*|*/     8       },
        {      0, 1,   /*|*/     4       },
        {      7, 8,   /*|*/     7       },
        {      8, 2,   /*|*/     2       },
        {      3, 5,   /*|*/     14      },
        {      2, 5,   /*|*/     4       }
    };

    cout << spanningTree(edges, edges.size());
    
    return 0;
}