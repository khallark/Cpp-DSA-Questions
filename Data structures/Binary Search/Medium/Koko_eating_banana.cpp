#include <iostream>
#include <vector>
using namespace std;
#define ull unsigned long long
int minEatingSpeed(vector<int>& piles, int h) {
    ull s = 1;
    ull hrs = h;
    ull sum = 0;
    for(int i : piles) sum += i;
    ull e = sum;
    ull mid = s + (e - s) / 2;
    int ans = 0;
    while(s <= e) {
        int numHrs = 0;
        for(auto pile : piles) {
            numHrs += (pile + mid - 1) / mid;
        }
        if(numHrs <= h) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main() {
    vector<int> piles = {3, 6, 7, 11};
    cout << minEatingSpeed(piles, 8);
    return 0;
}