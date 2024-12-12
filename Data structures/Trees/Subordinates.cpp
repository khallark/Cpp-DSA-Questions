#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> parents;
vector<vector<int>> tree;

int dfs(int node) {
    int count = 0;
    for(auto i : tree[node]) {
        count += dfs(i);
    }
    parents[node] = count;
    return count + 1;
}

int main() {
    cin >> n;
    tree.resize(n + 1);
    parents.resize(n + 1);
    for(int i = 2; i <= n; i++) cin >> parents[i];
    for(int i = 2; i <= n; i++) {
        tree[parents[i]].push_back(i);
    }
    dfs(1);
    for(int i = 1; i <= n; i++) cout << parents[i] << " ";
    cout << endl;
    return 0;
}