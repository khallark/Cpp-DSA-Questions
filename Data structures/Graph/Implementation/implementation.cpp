#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        // direction = 0 → undirected
        // direction = 1 → directed

        adj[u].push_back(v);

        if(direction == false) {
            adj[v].push_back(u);
        }
    }
    void print() {
        for(auto i : adj) {
            cout << i.first << ": ";
            for(auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};
int main() {
    graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(5, 6, 0);
    g.addEdge(7, 6, 0);
    g.addEdge(3, 2, 0);
    g.addEdge(2, 7, 0);
    g.print();
    return 0;
}