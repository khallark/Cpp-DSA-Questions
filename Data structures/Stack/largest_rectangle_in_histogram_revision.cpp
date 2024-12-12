#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> findNextSmallerElement(vector<int> arr) {
    vector<int> ans(arr.size());
    stack<int> smallers;
    smallers.push(-1);
    int i = arr.size() - 1;
    while(i >= 0) {
        while(smallers.top() != -1 && arr[smallers.top()] >= arr[i])
            smallers.pop();
        ans[i] = smallers.top();
        smallers.push(i);
        i--;
    }
    return ans;
}
vector<int> findPrevSmallerElement(vector<int> arr) {
    vector<int> ans(arr.size());
    stack<int> smallers;
    smallers.push(-1);
    int i = 0;
    while(i < arr.size()) {
        while(smallers.top() != -1 && arr[smallers.top()] >= arr[i])
            smallers.pop();
        ans[i] = smallers.top();
        smallers.push(i);
        i++;
    }
    return ans;
}
int LargestRectangle(vector<int> histogram) {
    vector<int> next(histogram.size());
    next = findNextSmallerElement(histogram);
    vector<int> prev(histogram.size());
    prev = findPrevSmallerElement(histogram);
    int ans = 0;
    for(int i = 0; i < histogram.size(); i++) {
        if(next[i] == -1)
            next[i] = histogram.size();
        int length = histogram[i];
        int breadth = next[i] - prev[i] - 1;
        int area = length * breadth;
        ans = area > ans ? area : ans;
    }
    return ans;
}
int main() {
    vector<int> arr = {2, 1, 5, 2, 3, 6};
    cout << LargestRectangle(arr) << endl;
    return 0;
}