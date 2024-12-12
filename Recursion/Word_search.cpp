#include <iostream>
#include <vector>
using namespace std;
bool solve(vector<vector<char>>& board, string word, int i, int j, int count) {
    if(count == word.length()) {
        return true;
    }
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == 0 || board[i][j] != word[count]) {
        return false;
    }
    char ch = board[i][j];
    board[i][j] = 0;
    bool check = solve(board, word, i + 1, j, count + 1) ||
                 solve(board, word, i, j + 1, count + 1) ||
                 solve(board, word, i - 1, j, count + 1) ||
                 solve(board, word, i, j - 1, count + 1);
    board[i][j] = ch;
    return check;
}
bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if(solve(board, word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    cout << exist(board, "ABCCE") << endl;
}