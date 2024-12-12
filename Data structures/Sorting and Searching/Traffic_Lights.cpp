#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct comp {
public:
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        int a_diff = a[1] - a[0];
        int b_diff = b[1] - b[0];
        if(a_diff != b_diff) {
            return a_diff > b_diff;
        }
        return a < b;
    }
};

int main() {
    ios::sync_with_stdio(0);
    int x, n;
    cin >> x >> n;
    vector<int> pols(n);
    for(auto& i : pols) cin >> i;
    multiset<int> pol;
    set<vector<int>, comp> dists;
    dists.insert({0, x});
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        auto it1 = pol.insert(pols[i]);
        auto end = pol.end();
        --end;
        int left, right;
        if(pol.size() == 1) {
            left = 0, right = x;
        } else if(it1 == pol.begin()) {
            auto temp = it1;
            left = 0;
            right = *++temp;
        } else if(it1 == end) {
            auto temp = it1;
            left = *--temp;
            right = x;
        } else {
            auto temp = it1;
            left = *--temp;
            temp = it1;
            right = *++temp;
        }
        auto it2 = dists.find({left, right});
        if(it2 != dists.end()) {
            dists.erase(it2);
        }
        dists.insert({left, *it1});
        dists.insert({*it1, right});
        vector<int> longest = *dists.begin();
        ans.push_back(longest[1] - longest[0]);
    }
    for(auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}