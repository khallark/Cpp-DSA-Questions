#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v = {3, 2, 1};
    next_permutation(v.begin(), v.end());
    for(auto i : v) {
        cout << i << endl;
    }
}