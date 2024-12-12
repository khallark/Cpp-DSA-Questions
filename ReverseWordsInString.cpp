#include <iostream>
using namespace std;
string reverseWords(string s) {
    int start = 0;
    int e = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i + 1] == ' ' || s[i + 1] == '\0') {
            int left = start;
            int right = i;
            while(left < right) {
                char temp =  s[left];
                s[left] = s[right];
                s[right] = temp;
                left++, right--;
            }
            i = i + 1;
            start = i + 1;
        }
    }
    return s;
}
int main() {
    string s = "Let's";
    cout << reverseWords(s) << endl;
    return 0;
}
