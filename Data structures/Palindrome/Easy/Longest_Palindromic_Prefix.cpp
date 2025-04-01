#include <iostream>
using namespace std;

string LongestPalindromicSubstring(string s) {
    int i = 0, j = s.length() - 1;
    int last = j;
    while(i < j) {
        if(s[i] == s[j]) {
            i++;
            j--;
        } else {
            last = j - (i == 0);
            if(!i) j--;
            i = 0;
        }
    }
    return s.substr(0, last + 1);
}

int main() {
    cout << endl << LongestPalindromicSubstring("abfgrhrgfbadmqwixufkjnwxe");
    return 0; //                                 -----------
}