#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <map>
#define pii pair<int, int>
using namespace std;
int n, q;

// O(q * N)
int main() {
    multiset<int> ms;
    vector<int> salary;
    vector<int> queries;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        ms.insert(num);
        salary.push_back(num);
    }
    for(int i = 0; i < q; i++) {
        char mode;
        int k, x;
        int a, b;
        cin >> mode;
        if(mode == '!') { // O(log N)
            cin >> k >> x;
            --k;
            auto it = ms.find(salary[k]);
            if (it != ms.end()) {
                ms.erase(it);
            }
            salary[k] = x;
            ms.insert(salary[k]);
        } else { // O(N)
            cin >> a >> b;
            auto l = ms.lower_bound(a);
            auto r = ms.upper_bound(b);
            queries.push_back(distance(l, r));
        }
    }
    for(auto i : queries) cout << i << endl;
    return 0;
}