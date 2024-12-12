#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to perform QR decomposition
void qr_decomposition(const vector<vector<double>>& A,
                      vector<vector<double>>& Q,
                      vector<vector<double>>& R) {
    int m = A.size();
    int n = A[0].size();

    Q.resize(m, vector<double>(n));
    R.resize(n, vector<double>(n));

    // Perform Gram-Schmidt process
    for (int j = 0; j < n; ++j) {
        vector<double> v(m);
        for (int i = 0; i < m; ++i) {
            v[i] = A[i][j];
        }
        for (int k = 0; k < j; ++k) {
            double dot_product = 0.0;
            for (int i = 0; i < m; ++i) {
                dot_product += Q[i][k] * A[i][j];
            }
            R[k][j] = dot_product;
            for (int i = 0; i < m; ++i) {
                v[i] -= R[k][j] * Q[i][k];
            }
        }
        double norm_v = 0.0;
        for (int i = 0; i < m; ++i) {
            norm_v += v[i] * v[i];
        }
        norm_v = sqrt(norm_v);
        R[j][j] = norm_v;
        for (int i = 0; i < m; ++i) {
            Q[i][j] = v[i] / norm_v;
        }
    }
}

int main() {
    vector<vector<double>> A = {{1, -1, 4},
                                           {2, 3, -1},
                                           {1, 0, 2}};
    
    vector<vector<double>> Q;
    vector<vector<double>> R;

    qr_decomposition(A, Q, R);

    cout << "Q:\n";
    for (const auto& row : Q) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    cout << "\nR:\n";
    for (const auto& row : R) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
