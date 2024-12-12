#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    if(((ll)n * (ll)(n + 1) / (ll)2) & 1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<int> v1, v2;
    ll sum = (ll)n * (ll)(n + 1) / (ll)4;
    while(sum != 0) {
        if(sum >= n) {
            v1.push_back(n);
            sum -= (ll)n;
            n--;
        } else {
            v2.push_back(n--);
        }
    }
    while(n) {
        v2.push_back(n--);
    }
    cout << v1.size() << endl;
    for(int i = v1.size() - 1; i >= 0; i--) {
        cout << v1[i] << " ";
    }
    cout << endl << v2.size() << endl;
    for(int i = v2.size() - 1; i >= 0; i--) {
        cout << v2[i] << " ";
    }
    cout << endl;
    return 0;
}