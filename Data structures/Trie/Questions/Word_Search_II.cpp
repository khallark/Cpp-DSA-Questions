#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Node {
public:
    vector<Node*> chars;
    bool isTerminal;
    Node() : chars(26, nullptr), isTerminal(false) {}
};

class Trie {
public:
    Node* head = new Node();
    Trie() {}
    void insert(string word) {
        Node *temp = head;
        for(auto i : word) {
            if(!temp->chars[i - 'a']) {
                Node* newC = new Node();
                temp->chars[i - 'a'] = newC;
            }
            temp = temp->chars[i - 'a'];
        }
        temp->isTerminal = true;
    }
    
    bool search(string word) {
        Node *temp = head;
        for(auto i : word) {
            if(!temp->chars[i - 'a']) {
                return false;
            }
            temp = temp->chars[i - 'a'];
        }
        return temp->isTerminal;
    }
};

class Solution {
private:
    vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    void dfs(vector<vector<char>>& board, set<string>& s,
    string output, Node* head, int i, int j) {
        if(head->isTerminal) {
            s.insert(output);
        }
        char temp = board[i][j];
        board[i][j] = '#';
        for(auto& k : dirs) {
            int I = i + k[0], J = j + k[1];
            if(I >= 0 && J >= 0 && I < board.size() && J < board[0].size() &&
            board[I][J] != '#' && head->chars[board[I][J] - 'a']) {
                dfs(board, s, output + board[I][J], head->chars[board[I][J] - 'a'], I, J);
            }
        }
        board[i][j] = temp;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        Trie t;
        set<string> s;
        for(auto &i : words) t.insert(i);
        Node *head = t.head;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(head->chars[board[i][j] - 'a']) {
                    dfs(board, s, string(1, board[i][j]),
                    head->chars[board[i][j] - 'a'], i, j);
                }
            }
        }
        vector<string> ans;
        for(auto& i : s) {
            ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    for(auto i : Solution().findWords(board, words)) {
        cout << i << " ";
    }
    return 0;
}