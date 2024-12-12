#include <iostream>
#include <vector>
using namespace std;

bool solve(string& s1, string& s2, string& s3, int i1, int i2, int i3) {
    if(i1 < s1.length()) 
    if(i2 < s2.length()) 
}

bool isInterleave1(string s1, string s2, string s3) {
    return solve(s1, s2, s3, 0, 0, 0);
}

int main() {
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    cout << isInterleave1(s1, s2, s3);
    return 0;
}