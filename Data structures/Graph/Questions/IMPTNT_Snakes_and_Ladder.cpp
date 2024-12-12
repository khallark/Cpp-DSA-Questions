#include <iostream>
#include <queue>
using namespace std;

int minStepsToWin(vector<vector<int>>& board) {
    int n = board.size();
    vector<int> flatBoard(n * n + 1);
    bool alt = false;
    int index = 1;
    for(int i = n - 1; i >= 0; i--) {
        if(!alt) {
            for(int j = 0; j < n; j++) {
                flatBoard[index++] = board[i][j];
            }
        } else {
            for(int j = n - 1; j >= 0; j--) {
                flatBoard[index++] = board[i][j];
            }
        }
        alt = !alt;
    }
    vector<bool> visited(n * n);

    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[0] = true;
    while(!q.empty()) {
        pair<int, int> temp = q.front();
        q.pop();
        int curr = temp.first;
        int steps = temp.second;
        if(curr == n * n) return steps;
        for(int i = curr + 1; i <= min(curr + 6, n * n); i++) {
            if(!visited[i]) {
                visited[i] = true;
                if(flatBoard[i] == -1) {
                    q.push({i, steps + 1});
                }
                else {
                    q.push({flatBoard[i], steps + 1});
                }
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<int>> board = {
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}
    };
    cout << minStepsToWin(board) << endl;
    return 0;
}