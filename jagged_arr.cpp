#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter n --> ";
    cin >> n;
    int *colSizes = new int[n];
    int **mainArr = new int *[n];
    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << "Enter column size of Row " << i + 1 << " --> ";
        cin >> colSizes[i];
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        mainArr[i] = new int[colSizes[i]];
        for(int j = 0; j < colSizes[i]; j++) {
            cout << "Enter the element (" << i << ", " << j << ") --> ";
            cin >> mainArr[i][j];
        }
        cout << endl;
    }
    cout << "The jagged array is shown below :- " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < colSizes[i]; j++) {
            cout << mainArr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}