#include <iostream>
#include <vector>
using namespace std;
int determinant(vector<vector<int>> matrix) {
    if(matrix.size() == 0 || matrix.size() == 1 || matrix.size() != matrix[0].size()) {
        return 0;
    }
    if(matrix.size() == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);
    }

    vector<vector<int>> m(matrix.size() - 1, vector<int>(matrix.size() - 1));
    vector<int> v(matrix.size());

    for(int k = 0; k < matrix.size(); k++) {
        int a = 0, b = 0;
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 0; j < matrix.size(); j++) {
                if(j != k) {
                    m[a][b++] = matrix[i][j];
                }
            }
            a++;
            b = 0;
        }
        v[k] = determinant(m); // the fuckin' monster right there
    }

    int ans = 0;
    int n = 1;
    for(int i = 0; i < v.size(); i++) {
        ans += v[i] * matrix[0][i] * n;
        n = 0 - n;
    }
    return ans;
}
int main() {
    vector<vector<int>> m = {{1, 1, 1, 1},
                             {1, 1, 1, 1},
                             {1, 1, 1, 1},
                             {1, 1, 1, 1}};
    cout << determinant(m) << endl;
    return 0;
}