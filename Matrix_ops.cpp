#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
double determinant(vector<vector<double>> matrix) {
    if(matrix.size() == 0) {
        return 1;
    }
    if(matrix.size() == 1) {
        return matrix[0][0];
    }
    if(matrix.size() == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);
    }
    vector<vector<double>> m(matrix.size() - 1, vector<double>(matrix.size() - 1));
    vector<double> v(matrix.size());
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
    double ans = 0;
    double n = 1;
    for(int i = 0; i < v.size(); i++) {
        ans += v[i] * matrix[0][i] * n;
        n = -n;
    }
    return ans;
}
vector<vector<double>> matrix_Inverse(vector<vector<double>> matrix) {
    vector<vector<double>> ans(matrix.size(), vector<double>(matrix.size()));
    double det = determinant(matrix); // determinant of the input matrix
    if(det == 0) {
        return {};
    }
    // computation of the cofactor matrix
    vector<vector<double>> m(matrix.size() - 1, vector<double>(matrix.size() - 1));
    const double tolerance = 1e-10;
    for(int i = 0; i < matrix.size(); i++) {
        for(int l = 0; l < matrix.size(); l++) {
            int a = 0, b = 0;
            int n = (i + l) % 2 == 0 ? 1 : -1;
            for(int j = 0; j < matrix.size(); j++) {
                if(j == i) continue;
                for(int k = 0; k < matrix.size(); k++) {
                    if(k != l){
                        m[a][b++] = matrix[j][k];
                    }
                }
                a++;
                b = 0;
            }
            double cofactor = (determinant(m) * n) / det;
            // Check if the value is very close to zero, if so, set it to zero
            if (fabs(cofactor) < tolerance) {
                cofactor = 0.0;
            }
            ans[l][i] = cofactor;
        }
    }
    // returning the answer
    return ans;
}
int main() {
    vector<vector<double>> a = {{3, 4, 1, 7}, 
                                {9, 1, 6, 8}, 
                                {2, 5, 1, 7},
                                {0, 3, 0, 1}};
    vector<vector<double>> b = matrix_Inverse(a);
    for(int i = 0; i < b.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}