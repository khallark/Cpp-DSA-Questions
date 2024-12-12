#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
int minValue(string s, int k){
    unordered_map<char, int> m;
    vector<char> v;
    priority_queue<int> q;
    for(int i = 0; i < s.length(); i++) {
        m[s[i]]++;
    }
    for(auto i: m) {
        q.push(i.second);
    }
    while(k) {
        int val = q.top();
        q.pop();
        val--, k--;
        q.push(val);
    }
    int ans = 0;
    while(!q.empty()) {
        ans += q.top() * q.top();
        q.pop();
    }
    return ans;
}
int main() {
    string s = "aabcbcbcabcc";
    cout << minValue(s, 3) << endl;
    return 0;
}