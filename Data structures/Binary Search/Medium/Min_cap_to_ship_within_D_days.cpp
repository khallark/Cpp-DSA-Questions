#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int shipWithinDays(vector<int>& weights, int days) {
    int s = *max_element(weights.begin(), weights.end());
    int e = 0;
    for(int i : weights) e += i;
    int mid = s + (e - s) / 2;
    int ans = e;
    while(s <= e) {
        int numDays = 1;
        int weight = 0;
        for(int i = 0; i < weights.size(); i++) {
            if(weight + weights[i] > mid) {
                numDays++;
                weight = weights[i];
            }
            else {
                weight += weights[i];
            }
        }
        if(numDays <= days) {
            ans = mid;
            e = mid - 1;
        }
        else s = mid + 1;
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main() {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    cout << shipWithinDays(weights, 5);
    return 0;
}