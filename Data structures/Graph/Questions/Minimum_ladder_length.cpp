#include <iostream>
#include <set>
#include <queue>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    set<string> s;
    for(auto i : wordList) {
        s.insert(i);
    }

    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    while(!q.empty()) {
        pair<string, int> p = q.front();
        q.pop();
        string word = p.first;
        int level = p.second;
        if(word == endWord) {
            return level;
        }
        string temp;
        for(int i = 0; i < beginWord.length(); i++){
            for(char j = 'a'; j <= 'z'; j++) {
                temp = word;
                temp[i] = j;
                auto it = s.find(temp);
                if(it != s.end()) {
                    s.erase(it);
                    q.push({temp, level + 1});
                }
            }
        }
    }
    return 0;
}
int main() {
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit";
    string endWord = "cog";
    cout << ladderLength(beginWord, endWord, wordList);
    return 0;
}