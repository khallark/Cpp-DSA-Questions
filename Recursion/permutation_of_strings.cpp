#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve(string str, vector<string>& ans, string output) {
    if(str.length() == 0) {
        ans.push_back(output);
        return;
    }
    for(int i = 0; i < str.length(); i++) {
        string temp = str;
        temp = temp.erase(temp.find(temp[i]), 1);
        solve(temp, ans, output + str[i]);
    }
}
vector<string> findPermutations(string str) {
    if(str.length() == 0) return {};
    vector<string> ans;
    string output = "";
    solve(str, ans, output);
    return ans;
}
int main() {
    string str = "ABC";
    vector<string> solution = findPermutations(str);
    cout << "[";
    for(int i = 0; i < solution.size(); i++) {
        if(i == solution.size() - 1) {
            cout << "\"" << solution[i] << "\"";
            continue;
        }
        cout << "\"" << solution[i] << "\"" << ",";
    }
    cout << "]" << endl;
    return 0;
}