#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
THE NAIVE APPROACH - SPOT OUT ALL THE POSSIBLE SUB-SEQUENCES OF THE STRING, AND CHOOSE THE REQUIRED ONES. HIGHLY INEFFICIENT, BOTH IN TERMS OF TIME COMPLEXITY [O(n)] AND SPACE COMPLEXITY (RECURSION)

bool isCorrect(string digits, string output) {
    vector<string> vals = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string alphas = "";
    for(int i = 0; i < digits.length(); i++) {
        if(vals[digits[i] - '0' - 1].find(output[i]) == string::npos) {
            return false;
        }
    }
    return true;
}
void solve(string digits, string alphas, string output, vector<string>& ans, int index) {
    if(index == alphas.length()) {
        if(output.length() == digits.length() && isCorrect(digits, output)) {
            ans.push_back(output);
        }
        return;
    }
    solve(digits, alphas, output, ans, index + 1);
    solve(digits, alphas, output + alphas[index], ans, index + 1);
}
vector<string> letterCombinations(string digits) {
    vector<string> vals = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string alphas = "";
    for(int i = 0; i < digits.length(); i++) {
        alphas = alphas + vals[digits[i] - '0' - 1];
    }
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(digits, alphas, output, ans, index);
    return ans;
}
*/

// THE SIGNIFICANCE OF BACKTRACKING - HELPS IN FINDING OUT ONLY THOSE REQUIRED, HENCE ELIMINATING ALL THE REDUNDANT FUNCTION CALL, WHICH MAKES IT EFFICIENT AND EFFECTIVE;

void solve(string digits, string output, vector<string>& ans, int index, vector<string>mappings) {
    if(index == digits.length()) {
        ans.push_back(output);
        return;
    }
    string mapped = mappings[digits[index] - '0'];
    for(int i = 0; i < mapped.length(); i++) {

        // MY FIRST THOUGHT:
        solve(digits, output + mapped[i], ans, index + 1, mappings);

        // BACK-TRACKING:
        /* output = output + mapped[i];
         solve(digits, output, ans, index + 1, mappings);
         output.pop_back();
        */
    }
}
vector<string> letterCombinations(string digits) {
    vector<string> vals = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output = "";
    vector<string> ans;
    int index = 0;
    solve(digits, output, ans, index, vals);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string nums = "89";
    vector<string> solution = letterCombinations(nums);
    cout << "[";
    for(int i = solution.size() - 1; i >= 0; i--) {
        if(i == 0) {
            cout << "\"" << solution[i] << "\"";
            continue;
        }
        cout << "\"" << solution[i] << "\"" << ",";
    }
    cout << "]" << endl;
    return 0;
}