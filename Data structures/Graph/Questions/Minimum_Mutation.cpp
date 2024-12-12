#include <iostream>
#include <set>
#include <queue>
using namespace std;

int minMutation(string startGene, string endGene, vector<string>& bank) {
    set<string> s;
    for(auto i : bank) {
        s.insert(i);
    }
    if(s.find(endGene) == s.end()) return -1;
    vector<char> genes = {'A', 'C', 'G', 'T'};
    queue<pair<string, int>> q;
    q.push({startGene, 0});
    s.erase(startGene);
    while(!q.empty()) {
        pair<string, int> temp = q.front();
        q.pop();
        string st = temp.first;
        int steps = temp.second;
        if(st == endGene) return steps;
        for(auto ch : genes) {
            for(int i = 0; i < st.size(); i++) {
                string mutate = st;
                mutate[i] = ch;
                if(mutate != st && s.find(mutate) != s.end()) {
                    s.erase(mutate);
                    q.push({mutate, steps + 1});
                }
            }
        }
    }
    return -1;
}

int main() {
    string startGene = "AACCGGTT", endGene = "AAACGGTA";
    vector<string> bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    cout << minMutation(startGene, endGene, bank);
    return 0;
}