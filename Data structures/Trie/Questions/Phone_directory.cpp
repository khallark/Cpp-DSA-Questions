#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class trie {
public:
    char data;
    bool terminal;
    unordered_map<char, trie*> children;
    priority_queue<char, vector<char>, greater<char>> lexo;
    trie(char data) : data(data), terminal(false) {}
};

void insert(trie *root, string contact) {
    for(char c : contact) {
        if(!root->children[c]) {
            root->children[c] = new trie(c);
            root->lexo.push(c);
        }
        root = root->children[c];
    }
    root->terminal = true;
}

void solve(trie *root, string output, vector<string>& ans) {
    if(root->lexo.empty()) {
        ans.push_back(output);
        return;
    }

    if(root->terminal) {
        ans.push_back(output);
    }
    priority_queue<char, vector<char>, greater<char>> q = root->lexo;
    while(!q.empty()) {
        char c = q.top();
        q.pop();
        solve(root->children[c], output + c, ans);
    }
}

vector<string> getVector(trie *root, string s) {
    vector<string> ans;
    string output = ""; 

    for(char c : s) {
        if(root->children.find(c) == root->children.end()) {
            ans.push_back("0");
            return ans;
        }
        root = root->children[c];
        output.push_back(c);
    }

    solve(root, output, ans);
    
    return ans;
}

vector<vector<string>> displayContacts(int n, string contact[], string s) {
    trie *root = new trie('\0');

    for(int i = 0; i < n; i++) {
        insert(root, contact[i]);
    }

    vector<vector<string>> ans;
    for(int i = 1; i <= s.length(); i++) {
        string word = s.substr(0, i);
        vector<string> v = getVector(root, word);
        ans.push_back(v);
    }

    return ans;
}

int main() {
    string contacts[] = {"abcde", "abcd", "abc", "ab", "a"};
    int n = sizeof(contacts) / sizeof(contacts[0]);
    string s = "abcdef";
    vector<vector<string>> ans = displayContacts(n, contacts, s);
    for(auto i : ans) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}