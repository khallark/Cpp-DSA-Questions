#include <iostream>
#include <vector>
using namespace std;

// TC = O(N * log M)
vector<int> peak_element_II(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int s = 0, e = m - 1;
    int mid = s + (e - s) / 2;
    while(s <= e) {
        int maxi = 0;
        int index = -1;
        for(int i = 0; i < n; i++) {
            if(maxi < mat[i][mid]) {
                index = i, maxi  = mat[i][mid];
            }
        }
        int left = mid - 1 >= 0 ? mat[index][mid - 1] : -1;
        int right = mid + 1 < m ? mat[index][mid + 1] : -1;
        if(mat[index][mid] > left && mat[index][mid] > right) return {index, mid};
        else if(mat[index][mid] <= left && mat[index][mid] > right) e = mid - 1;
        else if(mat[index][mid] > left && mat[index][mid] <= right) s = mid + 1;
        else {
            if(left > right) e = mid - 1;
            else s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return {};
}

int main() {
    vector<vector<int>> mat = {
        {10,20,15},
        {21,30,14},
        {7,16,3}
    };
    cout << peak_element_II(mat)[0] << "," << peak_element_II(mat)[1];
    return 0;
}