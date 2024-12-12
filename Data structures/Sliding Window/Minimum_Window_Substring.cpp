#include <iostream>
#include <unordered_map>
using namespace std;

/*
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in the 
window. If there is no such substring, return the empty string "".
*/

string minWindow(string s, string t) {
    int n = s.length();
    int len = t.length();
    unordered_map<char, int> m;
    for(auto& i : t) m[i]++;
    int l = 0, r = 0;
    int minLen = 1e9;
    int index = -1;
    int count = 0;
    while(r < n) {
        if(m[s[r]] > 0) count++;
        m[s[r]]--;
        r++;

        while(count == len) {
            if(r - l < minLen) {
                minLen = r - l;
                index = l;
            }
            m[s[l]]++;
            if(m[s[l]] > 0) count--;
            l++;
        }
    }
    if(index == -1) return "";
    return s.substr(index, minLen);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t) << endl;
    return 0;
}