#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applications(n);
    vector<int> apartments(m);
    for(auto& i : applications) cin >> i;
    for(auto& i : apartments) cin >> i;
    sort(applications.begin(), applications.end());
    sort(apartments.begin(), apartments.end());
    int i = 0, j = 0;
    int count = 0;
    while(i < n) {
        while(j < m) {
            if(abs(applications[i] - apartments[j]) <= k) {
                j++, count++;
                break;
            } else if(applications[i] < apartments[j]) {
                break;
            }
            j++;
        } i++;
    }
    cout << count << endl;
    return 0;
}