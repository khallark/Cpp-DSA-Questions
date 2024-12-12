#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& i : arr) cin >> i;
    map<int, int> m;
    int i = 0, j = 0;
    int maxCount = 1;
    while(j < n) {
        m[arr[j]]++;
        while(m[arr[j]] > 1) {
            m[arr[i]]--;
            i++;
        }
        maxCount = max(maxCount, j - i + 1);
        j++;
    }
    cout << maxCount << endl;
    return 0;
}