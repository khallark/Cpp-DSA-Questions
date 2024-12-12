#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class trie {
public:
    unordered_map<char, trie*> children;
    int count;
    trie() : count(0) {}
};
void insert(trie *root, string word) {
    while(word.length()) {
        if(!root->children[word[0]]) {
            root->children[word[0]] = new trie;
        }
        root = root->children[word[0]];
        root->count++;
        word = word.substr(1);
    }
}
string findPrefix(trie *root, string word) {
    string ans = "";
    for(char c : word) {
        root = root->children[c];
        ans.push_back(c);
        if(root->count == 1) {
            break;
        }
    }
    return ans;
}
vector<string> findPrefixes(string arr[], int n) {
    trie *root = new trie();
    for(int i = 0; i < n; i++) {
        insert(root, arr[i]);
    }
    vector<string> ans;
    for(int i = 0; i < n; i++) {
        ans.push_back(findPrefix(root, arr[i]));
    }
    return ans;
}

int main() {
    string arr[] = {"zebra", "dog", "duck", "dove"};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<string> ans = findPrefixes(arr, n);
    for(auto i : ans) {
        cout << "\"" << i << "\" ";
    }
    return 0;
}