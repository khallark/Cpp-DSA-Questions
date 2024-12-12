#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    ll X = 1;
    for(int i = 0; i < n; i++) {
        if(arr[i] > X) {
            break;
        }
        X += (ll)arr[i];
    }
    cout << X << endl;
    return 0;
}