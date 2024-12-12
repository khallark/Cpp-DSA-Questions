#include <iostream>
#include <queue>
using namespace std;

/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:
- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.

Return the minimum number of candies you need to have to distribute the candies to the children.
*/


// The solution I thought of, using the min head [O(nlogn)]
int candy1(vector<int>& ratings) {
    int n = ratings.size();
    if(n == 1) return 1;
    vector<int> candy(n, 1);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    for(int i = 0; i < n; i++) {
        q.push({ratings[i], i});
    }
    while(!q.empty()) {
        vector<int> temp = q.top();

        q.pop();

        int left = temp[1] - 1;
        int right = temp[1] + 1;

        if(left < 0) {
            if(ratings[right] >= temp[0]) candy[temp[1]] = 1;
            else candy[temp[1]] = candy[right] + 1;
            continue;
        }
        if(right == n) {
            if(ratings[left] >= temp[0]) candy[temp[1]] = 1;
            else candy[temp[1]] = candy[left] + 1;
            continue;
        }

        if(ratings[left] >= temp[0] && ratings[right] >= temp[0]) candy[temp[1]] = 1;

        else if(ratings[left] >= temp[0] || ratings[right] >= temp[0]) {
            if(ratings[left] > ratings[right]) candy[temp[1]] = candy[right] + 1;
            else candy[temp[1]] = candy[left] + 1;
        }

        else candy[temp[1]] = max(candy[left], candy[right]) + 1;
    }

    int ans = 0;
    for(auto& i : candy) ans += i;
    return ans;
}


// Better one [o(n)]
int candy2(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> LtoR(n, 1);
    vector<int> RtoL(n, 1);
    for(int i = 1; i < n; i++) {
        if(ratings[i] > ratings[i - 1]) {
            LtoR[i] = LtoR[i - 1] + 1;
        }
    }
    for(int i = n - 2; i >= 0; i--) {
        if(ratings[i] > ratings[i + 1]) {
            RtoL[i] = RtoL[i + 1] + 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += max(LtoR[i], RtoL[i]);
    }
    return ans;
}


int main() {
    vector<int> ratings = {1,2,87,87,87,2,1};
    cout << candy1(ratings) << endl;
    cout << candy2(ratings) << endl;
    return 0;
}