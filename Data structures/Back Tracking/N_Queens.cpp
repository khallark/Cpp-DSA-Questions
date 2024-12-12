#include <iostream>
#include <vector>
using namespace std;
void display(vector<vector<int>> v) {
    
    cout << "-";
    for(int k = 0; k < v.size(); k++) {
        cout << "---";
    }
    for(int k = 0; k < v.size(); k++) {
        cout << "-";
    }
    cout << endl;

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            if(v[i][j]) {
                cout << "| X ";
            }
            else {
                cout << "|   ";
            }
        }
        
        cout << "|" << endl << "-";
        for(int k = 0; k < v.size(); k++) {
            cout << "---";
        }
        for(int k = 0; k < v.size(); k++) {
            cout << "-";
        }
        cout << endl;
    }
}

void fill_attack_pos(vector<vector<int>>& v, int row, int col) {
    for(int i = 0; i < v.size(); i++) {
        if(i != col)
            v[row][i] = 0;
    }

    for(int i = 0; i < v.size(); i++) {
        if(i != row) {
            v[i][col] = 0;
        }
    }

    int i = row - 1, j = col - 1;
    while(i >= 0 && j >= 0) {
        v[i--][j--] = 0;
    }
    i = row + 1, j = col + 1;
    while(i < v.size() && j < v.size()) {
        v[i++][j++] = 0;
    }
    i = row - 1, j = col + 1;
    while(i >= 0 && j < v.size()) {
        v[i--][j++] = 0;
    }
    i = row + 1, j = col - 1;
    while(i < v.size() && j >= 0) {
        v[i++][j--] = 0;
    }
}

void solve(vector<vector<int>>board, vector<vector<vector<int>>>& ans, int row) {
    if(row == board.size()) {
        ans.push_back(board);
        return;
    }

    for(int i = 0; i < board.size(); i++) {

        if(board[row][i]) {
            vector<vector<int>> temp = board;
            fill_attack_pos(temp, row, i);
            solve(temp, ans, row + 1);
        }
    }
} 

vector<vector<vector<int>>> N_queens(int n) {
    vector<vector<vector<int>>> ans;
    vector<vector<int>> board(n, vector<int>(n, 1));
    solve(board, ans, 0);
    return ans;
}

int main() {
    vector<vector<vector<int>>> ans = N_queens(70);

    for(auto i : ans) {
        display(i);
        cout << endl;
    }
}