#include <iostream>
using namespace std;
bool isPalindrome(string str, int i) {
    if(str.length() - i - 1 >= i) return true;
    if(str[i] != str[str.length() - i - 1]) return false;
    return isPalindrome(str, i - 1);
}
int main() {
    string str = "abba";
    cout << isPalindrome(str, str.length() - 1);
    return 0;
}