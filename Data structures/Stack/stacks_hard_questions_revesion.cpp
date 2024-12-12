#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> nextSmallerElement(vector<int>& a) {
    vector<int> ans(a.size());
    stack<int> s;
    s.push(-1);
    int n = a.size() - 1;
    while(n >= 0) {
        while(s.top() != -1 && a[s.top()] >= a[n]) {
            s.pop();
        }
        ans[n] = s.top();
        s.push(n);
        n--;
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int>& a) {
    vector<int> ans(a.size());
    stack<int> s;
    s.push(-1);
    int n = 0;
    while(n < a.size()) {
        while(s.top() != -1 && a[s.top()] >= a[n]) {
            s.pop();
        }
        ans[n] = s.top();
        s.push(n);
        n++;
    }
    return ans;
}
int largestAreaInHistogram(vector<int> a) {
    vector<int> next(a.size());
    next = nextSmallerElement(a);
    vector<int> prev(a.size());
    prev = prevSmallerElement(a);
    int maxArea = 0;
    for(int i = 0; i < a.size(); i++) {
        if(next[i] == -1) next[i] = a.size();
        int width = next[i] - prev[i] - 1;
        int height = a[i];
        int area = width * height;
        maxArea = area > maxArea ? area : maxArea; 
    }
    return maxArea;
}
int largestRectangularAreaInBinaryMatrix(vector<vector<int>> a) {
    int maximum = largestAreaInHistogram(a[0]);
    for(int i = 1; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++) {
            if(a[i][j] != 0) a[i][j] = a[i][j] + a[i - 1][j];
            else a[i][j] = 0;
        }
        int area = largestAreaInHistogram(a[i]);
        maximum = area > maximum ? area : maximum;
    }
    return maximum;
}
int findCelebrity(vector<vector<int>> arr) {
    stack<int> s;
    for(int i = 0; i < arr.size(); i++) {
        s.push(i);
    }
    while(s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(arr[a][b] && arr[b][a]) continue;
        else if(arr[a][b]) s.push(b);
        else s.push(a);
    }
    if(s.size() == 0) return -1;
    return s.top();
}
int main() {
    vector<int> arr = {2, 1, 5, 3, 4, 2, 6};
    for(auto i: nextSmallerElement(arr)) {
        cout << i << " ";
    }
    cout << endl;
    for(auto i: prevSmallerElement(arr)) {
        cout << i << " ";
    }
    cout << endl;
    cout << largestAreaInHistogram(arr) << endl;
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 0, 0},
                               {1, 1, 1, 0},
                               {1, 1, 1, 1}};
    cout << largestRectangularAreaInBinaryMatrix(mat) << endl;
    vector<vector<int>> a = {{0, 1, 1},
                             {1, 0, 1},
                             {1, 1, 0}};
    cout << findCelebrity(a) << endl;
    return 0;
}