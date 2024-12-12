#include <iostream>
using namespace std;

/*

Given a string s and an integer k, return the length of the longest
substring of s such that the frequency of each characterin this
substring is greater than or equal to k.

If no such substring exists, return 0.

*/

int longestSubstring(string& s, int k) {
    int m[26] = {0};
    for(auto i : s) m[i - 'a']++;
    for(int i = 0; i < s.length(); i++) {
        if(m[s[i] - 'a'] > 0 && m[s[i] - 'a'] < k) { // The idea is to split the string from that position of character, which
        // doesn't even have a frequency of k, because no matter where is this character positioned, if included in the substring,
        // it will always make it invalid. Keep doing the split, until the whole slip is valid.
            string temp1 = s.substr(0, i);
            string temp2 = s.substr(i + 1, s.length() - i);
            return max(longestSubstring(temp1, k), longestSubstring(temp2, k));
        }
    }
    return s.length();
}

int main() {
    string s = "aaabb";
    cout << longestSubstring(s, 3);
    return 0;
}