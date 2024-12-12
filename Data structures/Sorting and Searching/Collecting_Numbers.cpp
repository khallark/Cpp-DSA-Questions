#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& i : arr) cin >> i;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == -1) continue;
        int temp = arr[i];
        arr[i] = -1;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] == -1) continue;
            if(arr[j] > temp) temp = arr[j], arr[j] = -1;
        }
        count++;
    }
    cout << count << endl;
    return 0;
}

// 9
// 6  2  8  3  4  1  9  5  7
//-1  2 -1  3  4  1 -1  5  7
//-1 -1 -1 -1 -1  1 -1 -1 -1
//-1 -1 -1 -1 -1 -1 -1 -1 -1