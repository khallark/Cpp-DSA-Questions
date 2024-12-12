#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    multiset<int> tickets;
    vector<int> customers(m);
    for(int i = 0; i < n; i++) {
        int price;
        cin >> price;
        tickets.insert(price);
    }
    for(auto& i : customers) cin >> i;
    vector<int> o;
    for(auto price : customers) {
        auto it = tickets.upper_bound(price);
        if(it == tickets.begin()) {
            o.push_back(-1);
        } else {
            --it;
            o.push_back(*it);
            tickets.erase(it);
        }
    }
    for(auto i : o) cout << i << endl;
    return 0;
}