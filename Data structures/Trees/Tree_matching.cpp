#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;
int n;
vector<pii> tree;

int main() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tree.push_back({x, y});
    }
    vector<bool> visited(n + 1, false);
    int maxCount = 0;
    for(int i = 0; i < tree.size(); i++) {
        visited.resize(n + 1, false);
        int count = 1;
        visited[tree[i].first] = visited[tree[i].second] = true;
        for(int j = i + 1; j < tree.size(); j++) {
            if(visited[tree[j].first] || visited[tree[j].second]) {
                continue;
            }
            visited[tree[j].first] = visited[tree[j].second] = true;
            count++;
        }
        maxCount = max(count, maxCount);
    }
    cout << maxCount << endl;
    return 0;
}