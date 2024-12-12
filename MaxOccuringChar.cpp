#include <iostream>
using namespace std;
char maxOccChar(string s) {
    int arr[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int numChar;
        if(ch >= 'a' || ch <= 'z') {
            numChar = ch - 'a';
        }
        else {
            numChar = ch - 'A';
        }
        arr[numChar]++;
    }
    int max = 0;
    int ans = -1;
    for (int i = 0; i < 26; i++) {
        if(arr[max] < arr[i]) {
            ans = i;
            max = i;
        }
    }
    return ans + 'a';
}
int main() {
    string s = "yoyo";
    cout << maxOccChar(s) << endl;
    return 0;
}