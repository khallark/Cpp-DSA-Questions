#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool possSol(vector<int>& arr, int m, int maxPages) {
    int numStds = 1, currNumPages = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(currNumPages + arr[i] <= maxPages) {
            currNumPages += arr[i];
        }
        else {
            numStds++;
            currNumPages = arr[i];
        }
    }
    return numStds <= m;
}
int findPages(vector<int>& arr, int n, int m) {
    if(n < m) return -1;
    int s = *max_element(arr.begin(), arr.end());
    int e = 0;
    for(auto i : arr) e += i;
    int mid = s + (e - s) / 2;
    int ans = 0;
    while(s <= e) {
        if(possSol(arr, m, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main() {
    vector<int> stalls = {25, 46, 28, 49, 24};
    int k = 4;
    cout << findPages(stalls, stalls.size(), 4);
    return 0;
}