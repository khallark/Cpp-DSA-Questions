#include <iostream>
#include <unordered_map>
using namespace std;

/*

Given a string s, find the length of the longest 
substring without repeating characters.

*/

int lengthOfLongestSubstring(string s) {
    int m[128] = {0};
    int maxLen = 0;
    int i = 0, j = 0;
    while(j < s.length()) {
        m[s[j]]++;
        while(m[s[j]] > 1) {
            m[s[i]]--;
            i++;
        }
        maxLen = max(maxLen, j - i + 1);
        j++;
    }
    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}