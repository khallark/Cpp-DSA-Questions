#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

pair<vector<int>, int> kadane_algorithm_finding_maximum_sum_contiguous_subArray(vector<int> v) {
    int sum = v[0];
    vector<int> vecmaxi; 
    vecmaxi.push_back(v[0]);
    int maxi = INT_MIN;
    for(int i = 1; i < v.size(); i++) {
        maxi = max(maxi, sum);
        if(sum < 0) {
            sum = 0;
            vecmaxi.clear();
        }
        sum += v[i];
        vecmaxi.push_back(v[i]);
    }
    maxi = max(maxi, sum);
    sum = 0;
    vector<int> ans;
    for(auto i : vecmaxi) {
        if(sum == maxi) {
            break;
        }
        ans.push_back(i);
        sum += i;
    }
    
    return make_pair(ans, maxi);
}

int main() {
    vector<int> v = {-1,2,3,-2,5};
    pair<vector<int>, int> p = kadane_algorithm_finding_maximum_sum_contiguous_subArray(v);
    cout << "Sub-array = {";
    for(int i = 0; i < p.first.size(); i++) {
        if(i < p.first.size() - 1) cout << p.first[i] << ", ";
        else cout << p.first[i] << "}" << endl;
    }
    cout << "Sum = " << p.second;
    return 0;
}