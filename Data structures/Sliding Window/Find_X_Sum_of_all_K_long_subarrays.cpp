#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

/*

You are given an array nums of n integers and two integers k and x.

The x-sum of an array is calculated by the following procedure:

Count the occurrences of all elements in the array.
Keep only the occurrences of the top x most frequent elements. If two
elements have the same number of occurrences, the element with the bigger
value is considered more frequent.

Calculate the sum of the resulting array.

Note that if an array has less than x distinct elements, its x-sum is the sum of the array.

Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the 
subarray
nums[i..i + k - 1].

Example 1:

Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2

Output: [6,10,12]

Explanation:

For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4.
Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.

*/

// NOT DONE (TLE)

class comp {
public:
bool operator()(const std::vector<int>& a, const std::vector<int>& b) const {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] > b[0];
    }
};
vector<long long> findXSum(vector<int>& nums, int k, int x) {
    set<vector<int>, comp> s;
    map<int, int> m;
    vector<long long> ans;
    int j = 0;
    for(j = 0; j < k; j++) {
        m[nums[j]]++;
        auto it = s.find({m[nums[j]] - 1, nums[j]});
        if(it != s.end()) s.erase(it);
        s.insert({m[nums[j]], nums[j]});
    }
    int num = x;
    long long sum = 0;
    for(auto i : s) {
        sum += (long long)i[0] * i[1];
        num--;
        if(num == 0) break;
    }
    ans.push_back(sum);
    int i = 0;
    while(j < nums.size()) {
        m[nums[i]]--;
        auto it = s.find({m[nums[i]] + 1, nums[i]});
        if(it != s.end()) s.erase(it);
        if(m[nums[i]]) s.insert({m[nums[i]], nums[i]});
        i++;
        m[nums[j]]++;
        it = s.find({m[nums[j]] - 1, nums[j]});
        if(it != s.end()) s.erase(it);
        s.insert({m[nums[j]], nums[j]});
        j++;
        num = x;
        sum = 0;
        for(auto I : s) {
            sum += (long long)I[0] * I[1];
            num--;
            if(num == 0) break;
        }
        ans.push_back(sum);
    }
    return ans;
}

int main() {
    vector<int> nums = {1,1,2,2,3,4,2,3}; int k = 6, x = 2;
    vector<long long> ans =  findXSum(nums, k, x);
    for(auto i : ans) {
        cout << i << " ";
    }
    return 0;
}