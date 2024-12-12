#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<string> allSubsqs(string& s) {
    int numSubs = pow(2, s.length()) - 1;
    vector<string> subs;
    for(int i = 0; i <= numSubs; i++) {
        string ans = "";
        int num = i;
        for(int j = s.length() - 1; j >= 0; j--) {
            if(num & 1) ans.push_back(s[j]);
            num = num >> 1;
        }
        reverse(ans.begin(), ans.end());
        subs.push_back(ans);
    }
    return subs;
}

int main() {
    string s = "123456";
    vector<string> ans = allSubsqs(s);
    for(auto i : ans) cout << "'" << i << "'" << " "; 
    return 0;
}