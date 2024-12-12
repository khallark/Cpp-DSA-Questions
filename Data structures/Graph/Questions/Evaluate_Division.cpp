#include <iostream>
#include <map>
#include <queue>
using namespace std;

double bfs(map<string, vector<pair<string, double>>>& graph, string& num, string& den) {
    if(graph[num].empty() || graph[den].empty()) return -1;
    queue<pair<string, double>> q;
    map<string, bool> visited;
    visited[num] = true;
    q.push({num, 1});
    while(!q.empty()) {
        pair<string, double> temp = q.front();
        q.pop();
        string st = temp.first;
        double val = temp.second;
        if(st == den) return val;
        for(auto i : graph[st]) {
            if(!visited[i.first]) {
                visited[i.first] = true;
                q.push({i.first, val * i.second});
            }
        }
    }
    return -1;
}
vector<double> calcEquation(vector<vector<string>>& equations,
vector<double>& values, vector<vector<string>>& queries) {
    map<string, vector<pair<string, double>>> graph;
    for(int i = 0; i < equations.size(); i++) {
        graph[equations[i][0]].push_back({equations[i][1], values[i]});
        graph[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
    }
    vector<double> ans;
    for(auto i : queries) {
        ans.push_back(bfs(graph, i[0], i[1]));
    }
    return ans;
}

int main() {
    vector<vector<string>> equations = {{"a","b"},{"b","c"},{"bc","cd"}};
    vector<double> values = {1.5, 2.5, 5.0};
    vector<vector<string>> queries = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
    vector<double> ans = calcEquation(equations, values, queries);
    for(auto i : ans) {
        cout << i << " ";
    }
    return 0;
}