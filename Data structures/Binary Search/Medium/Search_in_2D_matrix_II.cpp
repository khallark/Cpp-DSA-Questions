#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Solution I thought of [O(log M * log N)]
bool solve(vector<vector<int>>& matrix, int s, int e, int target) {
    if(s > e) return false;
    int mid = s + (e - s) / 2;
    auto it = lower_bound(matrix[mid].begin(), matrix[mid].end(), target);
    if (it != matrix[mid].end() && *it == target) return true;
    else return solve(matrix, s, mid - 1, target) ||
                solve(matrix, mid + 1, e, target);
}
bool searchMatrix1(vector<vector<int>>& matrix, int target) {
    return solve(matrix, 0, matrix.size() - 1, target);
}

// Most optimal Solution [O(m + n)]
bool searchMatrix2(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int row = 0;
    int col = n - 1;
    while(row < m && col >= 0) {
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] < target) row++;
        else col--;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,3}
    };
    cout << searchMatrix1(matrix, 5) << endl << searchMatrix2(matrix, 5);
    return 0;
}