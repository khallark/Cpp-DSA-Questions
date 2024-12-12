#include <iostream>
#include <vector>
using namespace std;

/*

There are several cards arranged in a row, and each card has an associated number of points.
The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row.
You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

*/

int maxScore(vector<int>& nums, int k) {
    int maxScore = 0;
    for(int i = 0; i < k; i++) {
        maxScore += nums[i];
    }
    int currentScore = maxScore;
    int i = k - 1;
    int j = nums.size() - 1;
    while(i >= 0) {
        currentScore = currentScore - nums[i] + nums[j];
        maxScore = max(maxScore, currentScore);
        i--, j--;
    }
    return maxScore;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,1};
    cout << maxScore(nums, 3);
    return 0;
}