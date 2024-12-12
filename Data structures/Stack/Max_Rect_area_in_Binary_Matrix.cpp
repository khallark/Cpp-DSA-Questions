#include <iostream>
#include <vector>
#include <stack>
using namespace std;
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
int Max_Rect_area_in_Binary_Matrix(vector<vector<int>> matrix) {
    int ans = largestRectangleArea(matrix[0]);
    for(auto i: matrix[0]) {
         cout << i << " ";
    }
    cout << endl;
    for(int i = 1; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            if(matrix[i][j] != 0)
                matrix[i][j] = matrix[i][j] + matrix[i - 1][j];
            else
                matrix[i][j] = 0;
        }
        for(auto i: matrix[i]) {
            cout << i << " ";
        }
        cout << endl;
        int area = largestRectangleArea(matrix[i]);
        ans = area > ans ? area : ans;
    }
    return ans;
}
int main() {
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 0, 0},
                               {1, 1, 1, 0},
                               {1, 1, 1, 1}};
    cout << Max_Rect_area_in_Binary_Matrix(mat) << endl;
    return 0;
}