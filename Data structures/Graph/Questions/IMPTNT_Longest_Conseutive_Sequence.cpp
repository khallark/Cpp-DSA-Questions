#include <iostream>
#include <unordered_map>
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
int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++) {
        if(m[nums[i]] == 0) m[nums[i]] = i + 1;
    }
    DisjointSet d(n);
    for(int i = 0; i < n; i++) {
        if(m[nums[i] - 1] > 0)
            d.unionBySize(m[nums[i]], m[nums[i] - 1]);
        if(m[nums[i] + 1] > 0)
            d.unionBySize(m[nums[i]], m[nums[i] + 1]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(d.findParent(i) == i) ans = max(ans, d.size[i]);
    }
    return ans;
}

int main() {
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout << longestConsecutive(nums) << endl;
    return 0;
}