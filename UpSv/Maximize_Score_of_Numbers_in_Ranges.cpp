#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
You are given an array of integers start and an integer d,
representing n intervals [start[i], start[i] + d].

You are asked to choose n integers where the ith integer must 
belong to the ith interval. The score of the chosen integers 
is defined as the minimum absolute difference between any two 
integers that have been chosen.

Return the maximum possible score of the chosen integers.


Example:
Input: start = [2,6,13,13], d = 5
Output: 5

Explanation:
The maximum possible score can be obtained by choosing integers: 2, 7, 13, and 18. 
The score of these chosen integers is 
min(|2 - 7|, |2 - 13|, |2 - 18|, |7 - 13|, |7 - 18|, |13 - 18|) 
which equals 5.
*/

bool canChooseWithMinDiff(vector<int>& start, int d, int minAbsDiff) {
    int num = start[0];
    for(int i = 1; i < start.size(); i++) {
        num = max(num + minAbsDiff, start[i]);
        if(num > start[i] + d) {
            return false;
        }
    }
    return true;
}

int maxPossibleScore(vector<int>& start, int d) {
    int n = start.size();
    sort(start.begin(), start.end());
    int left = 0;
    int right = (start[n - 1] + d) - start[0];
    int result = 0;
    int mid = left + (right - left) / 2;
    while(left <= right) {
        if(canChooseWithMinDiff(start, d, mid)) {
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
        mid = left + (right - left) / 2;
    }
    return result;
}

int main() {
    vector<int> start = {2, 6, 13, 13};
    cout << maxPossibleScore(start, 5);
}