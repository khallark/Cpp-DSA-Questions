#include <iostream>
using namespace std;

/*

You are given a string s and an integer k. You can choose
any character of the string and change it to any other
uppercase English character. You can perform this operation
at most k times.

Return the length of the longest substring containing the
same letter you can get after performing the above operations.

*/

int characterReplacement(string s, int k) {
    int m[26] = {0};
    int maxFreq = 0;
    int len = s.length();
    int maxLen = 0;
    int i = 0, j = 0;
    while(j < len) {
        m[s[j] - 'A']++;
        maxFreq = max(maxFreq, m[s[j] - 'A']);
        while((j - i + 1) - maxFreq > k) {
            m[s[i] - 'A']--;
            maxFreq = 0;
            for(int i = 0; i < 26; i++) {
                maxFreq = max(maxFreq, m[i]);
            }
            i++;
        }
        if((j - i + 1) - maxFreq <= k) maxLen = max(maxLen, j - i + 1);
        j++;
    }
    return maxLen;
}

int main() {
    string s = "AABAABBA";
    cout << characterReplacement(s, 1);
    return 0;
}