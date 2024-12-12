#include <iostream>
#include <stack>
using namespace std;
string rev(string s) {
    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        st.push(s[i]);
    }
    for(int i = 0; i < s.length(); i++) {
        s[i] = st.top();
        st.pop();
    }
    return s;
}
int main() {
    string s = "abcdefgh";
    cout << rev(s) << endl;
    return 0;
}