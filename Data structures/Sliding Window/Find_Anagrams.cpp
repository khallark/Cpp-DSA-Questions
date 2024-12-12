#include <iostream>
#include <vector>
using namespace std;

/*

Given two strings s and p, return an array of all the
start indices of p's anagrams in s. You may return the
answer in any order.

*/

vector<int> findAnagrams(string s, string p) {
    int k = p.length();
    if(k > s.length()) return {};
    vector<int> ans;
    int m[26] = {0};
    for(auto i : p) m[i - 'a']++;
    int count = 0;
    int i = 0, j;
    for(j = 0; j < k; j++) {
        if(m[s[j] - 'a'] > 0) count++;
        m[s[j] - 'a']--;
    }
    if(count == k) ans.push_back(i);
    while(j < s.length()) {
        m[s[i] - 'a']++;
        if(m[s[i] - 'a'] > 0) count--;
        i++;
        if(m[s[j] - 'a'] > 0) count++;
        m[s[j] - 'a']--;
        if(count == k) ans.push_back(i);
        j++;
    }
    return ans;
}

int main() {
    string s = "cbaebabacd", p = "abc";
    for(auto i : findAnagrams(s, p)) {
        cout << i << " ";
    }
    return 0;
}