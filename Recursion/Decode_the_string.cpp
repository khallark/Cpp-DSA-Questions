#include <iostream>
using namespace std;
string solve(string s, string str, int num, int index) {
    int check = index;
    for(int i = index; i < s.length(); i++) {
        if(check == 0 && s[i] == ']') continue;
        if(s[i] == ']') {
            break;
        }
        if(s[i] - '0' >= 1 && s[i] - '0' <= 9) {
            char a[4] = {'\0'};
            int cnt = 0;
            while(s[i] != '[') {
                a[cnt++] = s[i++];
            }
            a[cnt] = '\0';
            int temp = num;
            num = atoi(a);
            str = str + solve(s, "", num, i + 1);
            num = temp;
            while(s[i] != ']') {
                i++;
            }
        }
        else {
            str = str + s[i];
        }
    }
    string str2 = str;
    for(int i = 0; i < num - 1; i++) {
        str = str + str2;
    }
    return str;
}
string decodeString(string s) {
    string str = "";
    int num = 1;
    return solve(s, str, num, 0);
}
int main() {
    string code = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    string decode = decodeString(code);
    cout << decode << endl;
    return 0; 
}
// "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef"
// "zzzyypqjkjkefjkjkefjkjkefjkjkefefyypqjkjkefjkjkefjkjkefjkjkefefpqjkjkefjkjkefjkjkefjkjkefefef"