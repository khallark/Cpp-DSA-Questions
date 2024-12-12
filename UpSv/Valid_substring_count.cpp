#include <iostream>
using namespace std;

/*
You are given two strings word1 and word2.
A string x is called valid if x can be rearranged to have word2 as a prefix.
Return the total number of valid substrings of word1.
*/

long long validSubstringCount(string word1, string word2) {
    int n = word1.length();
    int m[26] = {0};
    for(auto i : word2) m[i - 'a']++;
    int i = 0, j = 0;
    int all = 0;
    long long ans = 0;
    while(j < n) {
        if(m[word1[j] - 'a'] > 0) all++;
        m[word1[j] - 'a']--;
        j++;
        while(all == word2.length()) {
            ans += n - (j - 1);
            m[word1[i] - 'a']++;
            if(m[word1[i] - 'a'] > 0) all--;
            i++;
        }
    }
    return ans;
}

int main() {
    string word1 = "abcabc", word2 = "abc";
    cout << validSubstringCount(word1, word2);
    return 0;
}