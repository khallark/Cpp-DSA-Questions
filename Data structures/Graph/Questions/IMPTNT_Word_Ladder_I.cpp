#include <iostream>
#include <set>
#include <queue>
#include <utility>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    set<string> s;
    for(auto i : wordList) s.insert(i);
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    int ans = 0;
    while(!q.empty()) {
        pair<string, int> temp = q.front();
        if(temp.first == endWord) {
            ans = temp.second;
            break;
        }
        q.pop();
        string word;
        for(int k = 0; k < 3; k++) {
            for(char i = 'a'; i <= 'z'; i++) {
                word = temp.first;
                word[k] = i;
                auto it = s.find(word);
                if(it != s.end()) {
                    s.erase(it);
                    q.push({word, temp.second + 1});
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<string> words = {"hot","dot","dog","lot","log","cog"};
    string s = "hit", e = "cog";
    cout << ladderLength(s, e, words);
    return 0;
}