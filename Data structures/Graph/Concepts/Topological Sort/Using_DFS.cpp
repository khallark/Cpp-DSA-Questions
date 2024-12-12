#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
// void dfs(vector<int> adj[], vector<bool>& visited, stack<int>& s, int node) {
//     visited[node] = true;
//     for(auto i : adj[node]) {
//         if(!visited[i]) {
//             dfs(adj, visited, s, i);
//         }
//     }
//     s.push(node);
// }
// vector<int> topological_sort(vector<int> adj[], int n) {
//     stack<int> s;
//     vector<int> ans;
//     vector<bool> visited(n, false);
//     for (int i = 0; i < n; i++) {
//         if (!visited[i])
//             // cout << i << " is visited" << endl;
//             dfs(adj, visited, s, i);
//     }
//     // dfs(adj, visited, s, 0);
//     while(!s.empty()) {
//         ans.push_back(s.top());
//         s.pop();
//     }
//     return ans;
// }
void topologicalSortUtil(int v, vector<int> adj[],
                         vector<bool>& visited,
                         stack<int>& Stack)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all adjacent vertices
    for (int i : adj[v]) {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    // Push current vertex to stack which stores the result
    Stack.push(v);
}

// Function to perform Topological Sort
vector<int> topologicalSort(vector<int> adj[], int V)
{
    stack<int> Stack; // Stack to store the result
    vector<bool> visited(V, false);

    // Call the recursive helper function to store
    // Topological Sort starting from all vertices one by
    // one
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    vector<int> ans;
    // Print contents of stack
    while (!Stack.empty()) {
        ans.push_back(Stack.top());
        Stack.pop();
    }

    return ans;
}
int main() {
    vector<int> adj[] = {
        {1},
        {2, 3, 4},
        {5},
        {},
        {1, 5},
        {2},
        {7, 9},
        {5, 10},
        {6},
        {8},
        {11},
        {9}
    };
    for(auto i : topologicalSort(adj, 12)) {
        cout << i << " ";
    }
    return 0;
}

