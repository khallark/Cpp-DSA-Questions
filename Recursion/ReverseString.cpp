#include <iostream>
#include <algorithm>
using namespace std;
void revStr1(string &str, int i, int j) {
    if(i >= j) return;
    revStr1(str, i + 1, j - 1);
    swap(str[i], str[j]);
}
void revStr2(string &str, int i) {
    if(str.length() - i - 1 >= i) return;
    revStr2(str, i - 1);
    swap(str[str.length() - i - 1], str[i]);
}
int main() {
    string str = "oi";
    revStr2(str, str.length() - 1);
    cout << str << endl;
    return 0;
}