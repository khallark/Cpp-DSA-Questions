#include <iostream>
#include <stack>
using namespace std;
int findMinCost(string s) {
    if(s.length() & 1) return -1;
    stack<int> mystack;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '{')
            mystack.push(s[i]);
        else {
            if(mystack.empty() || mystack.top() == '}')
                mystack.push(s[i]);
            else if(mystack.top() == '{')
                mystack.pop();
        }
    }
    int size = mystack.size();
    int a = 0;
    while(!mystack.empty()) {
        if(mystack.top() == '{') a++;
        mystack.pop();
    }
    int b = size - a;
    return ((a + 1) / 2) + ((b + 1) / 2);
}
int main() {
    string s = "{{{{}{{}}{";
    cout << findMinCost(s) << endl;
    return 0;
}