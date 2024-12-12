#include <iostream>
#include <vector>
#include <stack>
#include <matrix.h>
using namespace std;

int maximal_area(vector<int>& arr) {
    int n = arr.size();
    stack<int> s;
    s.push(-1);
    vector<int> nextSmaller(n);
    for(int i = n - 1; i >= 0; i--) {
        while(s.top() != -1 && arr[s.top()] >= arr[i]) s.pop();
        if(s.top() == -1) nextSmaller[i] = n;
        else if(arr[s.top()] < arr[i]) nextSmaller[i] = s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    s.push(-1);
    vector<int> prevSmaller(n);
    for(int i = 0; i < n; i++) {
        while(s.top() != -1 && arr[s.top()] >= arr[i]) s.pop();
        if(s.top() == -1) prevSmaller[i] = -1;
        else if(arr[s.top()] < arr[i]) prevSmaller[i] = s.top();
        s.push(i);
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int b = nextSmaller[i] - prevSmaller[i] - 1;
        int h = arr[i];
        int s = min(b, h);
        ans = max(ans, s * s);
    }

    return ans;
}

int maximal_square(vector<vector<int>>& arr) {
    int m = arr.size();
    int n = arr[0].size();
    vector<int> heights(n);
    int ans = 0;
    for(int i = 0; i < n; i++) heights[i] = arr[0][i];
    ans = max(ans, maximal_area(heights));

    for(int i = 1; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == 0) heights[j] = 0;
            else heights[j] += arr[i][j];
        }
        ans = max(ans, maximal_area(heights));
    }
    
    return ans;
}
 
int main() {
    vector<vector<int>> arr = {
        {0, 1, 0, 1, 1, 1, 1},
        {0, 1, 0, 0, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 0, 0}
    };
    cout << maximal_square(arr);
    return 0;
}