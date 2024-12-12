#include <iostream>
#include <vector>
// #include <set>
#include <queue>
#include <algorithm>
#include <climits>
#define nl endl
using namespace std;

struct comp {
public:
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return a[0] < b[0];
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    int index = 0;
    for(auto& i : arr) {
        int x, y;
        cin >> x >> y;
        i = {x, y, index++};
    }
    sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    });

    vector<int> ans(n, -1);
    int lastRoom = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> roomTime;

    for(int i = 0; i < n; i++) {
        vector<int> v = arr[i];
        if(roomTime.size() == 0) {
            ans[v[2]] = lastRoom++;
            roomTime.push({v[1], lastRoom - 1});
        }
        else {
            pair<int, int> avail = roomTime.top();
            if(avail.first < v[0]) {
                ans[v[2]] = avail.second;
                roomTime.pop();
                roomTime.push({v[1], avail.second});
            } else {
                ans[v[2]] = lastRoom++;
                roomTime.push({v[1], lastRoom - 1});
            }
        }
    }

    cout << lastRoom - 1 << nl;
    for(auto i : ans) cout << i << " ";
    cout << nl;

    return 0;
}