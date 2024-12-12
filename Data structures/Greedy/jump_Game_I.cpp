#include <iostream>
#include <vector>
using namespace std;
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxReach = 0;
    for(int i = 0; i < n; i++) {
        if(i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
}
int main() {
    vector<int> jumps = {3, 2, 1, 0, 4};
    cout << canJump(jumps);
    return 0;
}