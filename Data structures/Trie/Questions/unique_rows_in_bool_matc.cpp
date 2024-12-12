#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#define MAX 1000
using namespace std;

class trie {
public:
    int data;
    bool done;
    pair<trie*, trie*> children;
    trie(int data) : data(data), done(false) {}
};

void insert(trie *root, int booleans[], int n) {
    for(int i = 0; i < n; i++) {
        if(!root->children.first) {
            root->children.first = new trie(booleans[i]);
            root = root->children.first;
        }
        else if(root->children.first->data == booleans[i]) {
            root = root->children.first;
        }
        else if(!root->children.second) {
            root->children.second = new trie(booleans[i]);
            root = root->children.second;
        }
        else {
            root = root->children.second;
        }
    }
}

vector<int> solve(trie *root, int M[], int n) {
    vector<int> temp;
    for(int i = 0; i < n; i++) {
        temp.push_back(M[i]);
        if(root->children.first && root->children.first->data == M[i]) {
            root = root->children.first;
        }
        else if(root->children.second && root->children.second->data == M[i]){
            root = root->children.second;
        }
        if(i == n - 1 && root->done) {
            return {};
        }
        else {
            root->done = true;
        }
    }
    return temp;
}

vector<vector<int>> uniqueRows(int M[MAX][MAX],int row,int col) {
    trie *root = new trie('\0');
    for(int i = 0; i < row; i++) {
        insert(root, M[i], col);
    }

    vector<vector<int>> ans;
    vector<int> output;
    for(int i = 0; i < row; i++) {
        vector<int> temp = solve(root, M[i], col);
        if(!temp.empty()) {
            ans.push_back(temp);
        }
    }
    return ans;
}

int main() {
    int M[][MAX] = {{1, 1, 0, 1},
                    {0, 1, 1, 1},
                    {1, 1, 0, 1},
                    {1, 1, 1, 1},
                    {0, 0, 1, 1},
                    {1, 0, 1, 1},
                    {1, 0, 0, 1},
                    {0, 0, 0, 0},
                    {0, 1, 1, 1},
                    {1, 0, 0, 1},
                    {0, 0, 1, 1},
                    {0, 1, 1, 0},
                    {0, 0, 0, 0},
                    {1, 0, 1, 0}};
    int row = 14, col = 4;
    vector<vector<int>> ans = uniqueRows(M, row, col);
    for(auto i : ans) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}