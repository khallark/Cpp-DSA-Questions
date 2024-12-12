#include <iostream>
using namespace std;

/*

Given two strings s1 and s2, return true if s2 contains a 
permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is
the substring of s2.

*/

bool checkInclusion(string p, string s) {
    int k = p.length();
    if(k > s.length()) return {};
    int m[26] = {0};
    for(auto i : p) m[i - 'a']++;
    int count = 0;
    int i = 0, j;
    for(j = 0; j < k; j++) {
        if(m[s[j] - 'a'] > 0) count++;
        m[s[j] - 'a']--;
    }
    if(count == k) return true;
    while(j < s.length()) {
        m[s[i] - 'a']++;
        if(m[s[i] - 'a'] > 0) count--;
        i++;
        if(m[s[j] - 'a'] > 0) count++;
        m[s[j] - 'a']--;
        if(count == k) return true;
        j++;
    }
    return false;
}

int main() {
    string s = "eidbaooo";
    string p = "ab";
    cout << checkInclusion(p, s);
    return 0;
}