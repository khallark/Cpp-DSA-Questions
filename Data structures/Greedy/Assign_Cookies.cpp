#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int assign_cookies(vector<int> &greed, vector<int> &cookies) {

    // The idea here, is to sort both the lists, and greedily map the children with the optimal cooky.
    // Greedy approach works here, because of the pattern, that LARGER GREEDs CAN ONLY BE MAPPED TO LARGER COOKIES.
    sort(greed.begin(), greed.end());
    sort(cookies.begin(), cookies.end());

    int i = 0, j = 0;

    while(i < cookies.size() && j < greed.size()) {
        if(cookies[i] >= greed[j]) j++; 
        i++;
    }

    return j;
}

int main() {
    vector<int> greed_factor = {1, 5, 3, 3, 4};
    vector<int> cookies = {4, 2, 1, 2, 1, 3};
    cout << assign_cookies(greed_factor, cookies);
    return 0;
}