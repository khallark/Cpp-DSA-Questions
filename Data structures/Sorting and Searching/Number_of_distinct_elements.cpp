#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, bool> m;
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) m[arr[i]];
    cout << m.size() << endl;
    return 0;
}