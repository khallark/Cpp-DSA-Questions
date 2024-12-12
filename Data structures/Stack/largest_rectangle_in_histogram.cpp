#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

// Brute Force Solution o(n^2):
int findMaxArea(vector<int> heights, int num) {
    int br = 1;
    for(int i = num - 1; i >= 0; i--) {
        if(heights[num] > heights[i]) {
            break;
        }
        br++;
    }
    for(int i = num + 1; i < heights.size(); i++) {
        if(heights[num] > heights[i]) {
           break; 
        }
        br++;
    }
    return heights[num] * br;
}
int largestRect_brute_force(vector<int> heights) {
    int max = 0;
    for(int i = 0; i < heights.size(); i++) {
        int area = findMaxArea(heights, i);
        max = area > max ? area : max;
    }
    return max;
}

// Optimized Solution using STACK O(n):
vector<int> nextSmallerElement(vector<int> heights) {
    stack<int> s;
    vector<int> ans(heights.size());
    s.push(-1);
    int n = heights.size() - 1;
    while(n >= 0) {
        while(s.top() != -1 && heights[s.top()] >= heights[n]) 
            s.pop();
        ans[n] = s.top();
        s.push(n);
        n--;
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int> heights) {
    stack<int> s;
    vector<int> ans(heights.size());
    s.push(-1);
    int n = 0;
    while(n < heights.size()) {
        while(s.top() != -1 && heights[s.top()] >= heights[n]) 
            s.pop();
        ans[n] = s.top();
        s.push(n);
        n++;
    }
    return ans;
}
int largestRectangleArea(vector<int> heights) {
    vector<int> nextSmallers(heights.size());
    nextSmallers = nextSmallerElement(heights);
    vector<int> prevSmallers(heights.size());
    prevSmallers = prevSmallerElement(heights);
    int max = 0;
    for(int i = 0; i < heights.size(); i++) {
        int next = nextSmallers[i] == -1 ? heights.size() : nextSmallers[i];
        int prev = prevSmallers[i];
        int area = heights[i] * (next - prev - 1);
        max = area > max ? area : max;
    }
    return max;
}

int main() {
    vector<int> heights = {2, 1, 5, 3, 4, 2, 6};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}