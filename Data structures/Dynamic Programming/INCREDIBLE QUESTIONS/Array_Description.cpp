#include <iostream>
#include <vector>
using namespace std;
const int M = 1000000007;
int array_desc(vector<int>& arr, int n, int m) {
    vector<int> curr(m + 1);
    int num = arr[n - 1] == 0 ? 1 : 0;
    vector<int> next(m + 1, num);
    next[arr[n - 1]] = 1;
    next[0] = 0;
    for(int i = n - 2; i >= 0; i--) {
        int s, e;
        if(arr[i] != 0) {
            s = (arr[i] > 1) ? -1 : 0, e = (arr[i] < m) ? 1 : 0;
            for(int k = s; k <= e; k++) {
                curr[arr[i]] = (curr[arr[i]] + next[arr[i] + k] + 0LL) % M;
            }
        }
        else{
            for(int j = 1; j <= m; j++) {
                s = (j > 1) ? -1 : 0, e = (j < m) ? 1 : 0;
                for(int k = s; k <= e; k++) {
                    curr[j] = (curr[j] + next[j + k] + 0LL) % M;
                }
            }
        }
        next = curr;
        curr = vector<int>(m + 1);
    }
    int ans = 0;
    for(auto i : next) ans = (ans + i + 0LL) % M;
    return ans;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(auto& i : arr) {
        cin >> i;
    }
    cout << array_desc(arr, n, m) << endl;
    return 0;
}