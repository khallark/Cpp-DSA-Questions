#include <iostream>
#include <vector>
using namespace std;
int n, q;
vector<vector<int>> forest;
vector<vector<int>> prefixSum;
int main() {
    cin >> n >> q;
    forest.resize(n, vector<int>(n));
    prefixSum.resize(n + 1, vector<int>(n + 1));
    for(auto& i : forest) {
        for(auto& j : i) {
            char c;
            cin >> c;
            j = (c == '.') ? 0 : 1;
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            prefixSum[i + 1][j + 1] = prefixSum[i + 1][j] + forest[i][j];

    for(int j = 0; j < n; j++)
        for(int i = 0; i < n; i++)
            prefixSum[i + 1][j + 1] += prefixSum[i][j + 1];

    /*
        0  1  0  0  1               0  1  1  1  2
        1  0  1  1  0               1  2  3  4  5
        1  1  0  0  1     ---->     2  4  5  6  8
        1  1  1  1  0               3  6  8  10 12
        1  0  1  1  1               4  7  10 13 16
    */

    vector<int> queries;
    for(int i = 0; i < q; i++) {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        queries.push_back(  
           + prefixSum[i2][j2] // Total sum from (0, 0) to (i2-1, j2-1).
           - prefixSum[i1 - 1][j2] // Total sum from (0, 0) to (i1-2, j2-1) (removing the area above the rectangle).
           - prefixSum[i2][j1 - 1] // Total sum from (0, 0) to (i2-1, j1-2) (removing the area to the left of the rectangle).
           + prefixSum[i1 - 1][j1 - 1] // This term is added back since it is subtracted twice (once in each of the previous
           // two subtractions). It represents the area that was counted in both the removed top and left sections.
        );
    }
    for(auto i : queries) {
        cout << i << endl;
    }
    return 0;
}