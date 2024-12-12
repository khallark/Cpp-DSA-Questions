#include <iostream>
#include <vector>
using namespace std;
void solve(string str, vector<string>& ans, string output, int index) {
    if(index == str.length()) {
        if(output != "") {
            ans.push_back(output);
        }
        return;
    }
    solve(str, ans, output, index + 1);
    solve(str, ans, output + str[index], index + 1);
}
vector<string> subsequences(string str) {
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, ans, output, index);
    return ans;
}
int main() {
    string str = "asdfghjklqwerty";
    vector<string> SubSeqs = subsequences(str);
    cout << "(";
    for(int i = 0; i < SubSeqs.size(); i++) {
        if(i == SubSeqs.size() - 1) {
            cout << "\"" << SubSeqs[i] << "\"";
            continue;
        }
        cout << "\"" << SubSeqs[i] << "\"" << ", ";
    }
    cout << ")" << endl;
    return 0;
}