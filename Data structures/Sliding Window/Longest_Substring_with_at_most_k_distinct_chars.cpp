#include <iostream>
using namespace std;

/*

You are given a string 'str' and an integer ‘K’.
Your task is to find the length of the largest
substring with at most ‘K’ distinct characters.

For example:
You are given ‘str’ = ‘abbbbbbc’ and ‘K’ = 2,
then the substrings that can be formed are
[‘abbbbbb’, ‘bbbbbbc’]. Hence the answer is 7.

*/

int lengthOfLongestSubstring(string s, int k) {
    int m[26] = { 0 };
    int count = 0;
    int i = 0, j = 0;
    int maxLen = 0;
    while(j < s.length()) {
        if(m[s[j] - 'a'] == 0) count++;
        m[s[j] - 'a']++;
        if(count <= k) maxLen = max(maxLen, j - i + 1);
        j++;
        while(count > k) {
            m[s[i] - 'a']--;
            if(m[s[i] - 'a'] == 0) count--;
            i++;
        }
    }
    return maxLen;
}

int main() {
    string s = "ninninja";
    cout << lengthOfLongestSubstring(s, 2);
    return 0;
}