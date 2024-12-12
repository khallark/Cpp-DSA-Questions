#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int celebrity_n_square(vector<vector<int>>& M, int n) {
    for(int i = 0; i < M.size(); i++) {
        for(int j = 0; j < M.size(); j++) {
            if(i == j) continue;
            if(M[i][j]) M[i][i]++, M[j][j]--;
        }
    }
    int expected = 0 - (M.size() - 1);
    for(int i = 0; i < M.size(); i++) {
        if(M[i][i] == expected) return i;
    }
    return -1;
}
int celebrity_n(vector<vector<int>>& M, int n) {
    stack<int> s;
    for(int i = 0; i < n; i++) {
        s.push(i);
    }
    while(s.size() > 1) {
        // if stack size = 0, then there is no celebrity

        // Taking the top 2 party members
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        // The one who doesn't know the other, goes back to the stack again
        if(M[a][b] && M[b][a]) continue;
        else if(M[a][b]) s.push(b);
        else s.push(a);
    }
    if(s.size() == 0) return -1;
    return s.top();
}
int main() {
    vector<vector<int>> a = {{0, 1, 1},
                             {1, 0, 1},
                             {1, 1, 0}};
    cout << celebrity_n_square(a, a.size()) << endl;
    return 0;
}