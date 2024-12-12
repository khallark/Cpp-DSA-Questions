#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pii> movies(n);
    for(auto& i : movies) cin >> i.first >> i.second;
    sort(movies.begin(), movies.end(), [](pii& a, pii& b) {
        return a.second < b.second;
    });
    int last_finish_time = movies[0].second;
    int count = 1;
    for(int i = 1; i < n; i++) {
        pii interval = movies[i];
        if(interval.first >= last_finish_time) {
            count++;
            last_finish_time = interval.second;
        }
    }
    cout << count << endl;
    return 0;
}