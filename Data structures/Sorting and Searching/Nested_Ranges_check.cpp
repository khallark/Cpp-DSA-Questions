#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> ranges(n);
    int ind = 0;
    for(auto& i : ranges) {
        int x, y;
        cin >> x >> y;
        i = {x, y, ind++};
    }
    sort(ranges.begin(), ranges.end(), [](vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    vector<bool> contains(n, false);
    vector<bool> contained(n, false);

    // Check if element contains or not
    int minRB = INT_MAX;
    for(int i = n - 1; i >= 0; i--) {
        if(ranges[i][1] >= minRB) {
            contains[ranges[i][2]] = true;
        }
        minRB = min(minRB, ranges[i][1]);
    }

    // Check if element is contained or not
    int maxRB = 0;
    for(int i = 0; i < n; i++) {
        if(ranges[i][1] <= maxRB) {
            contained[ranges[i][2]] = true;
        }
        maxRB = max(maxRB, ranges[i][1]);
    }

    for(auto i : contains) cout << i << " ";
    cout << endl;
    for(auto i : contained) cout << i << " ";
    cout << endl;

    return 0;
}