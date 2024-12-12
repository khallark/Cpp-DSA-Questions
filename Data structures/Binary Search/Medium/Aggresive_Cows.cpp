#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool possibleSol(vector<int>& stalls, int minDist, int k) {
    int numCows = 1;
    int lastCowIndex = 0;
    for(int i = 1; i < stalls.size() && numCows < k; i++) {
        if(stalls[i] - stalls[lastCowIndex] >= minDist) {
            lastCowIndex = i;
            numCows++;
        }
    }
    return numCows == k;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s = 0, e = stalls.back();
    int mid = s + (e - s) / 2;
    int ans = 0;
    while(s <= e) {
        if(possibleSol(stalls, mid, k)) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main() {
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    cout << aggressiveCows(stalls, k);
    return 0;
}