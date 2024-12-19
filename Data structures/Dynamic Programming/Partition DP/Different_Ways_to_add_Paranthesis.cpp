#include <iostream>
#include <vector>
#include <myList.h>
using namespace std;

int n;
vector<vector<vector<int>>> dp;
vector<int> operands;
vector<char> operators;

void seperate(string s) {
    int N = s.length();
    int i = 0;
    while(i < N) {
        string temp = "";
        while(i < N and (s[i] != '+' and s[i] != '-' and s[i] != '*')) {
            temp += s[i];
            i++;
        }
        operands.push_back(stoi(temp));
        if(i < N) {
            operators.push_back(s[i]);
            i++;
        }
    }
}
vector<int> f(int l, int r) {
    if(l == r) return {operands[l]};
    if(!dp[l][r].empty()) return dp[l][r];
    vector<int> ans;
    for(int m = l; m < r; m++) {
        vector<int> left = f(l, m);
        vector<int> right = f(m + 1, r);
        char opr = operators[m];
        for(auto i : left) {
            for(auto j : right) {
                int val;
                if(opr == '+') {
                    val = i + j;
                } else if(opr == '-') {
                    val = i - j;
                } else {
                    val = i * j;
                }
                ans.push_back(val);
            }
        }
    }
    return dp[l][r] = ans;
}
vector<int> diffWaysToCompute(string expression) {
    if(expression.length() == 1) return {stoi(string(1, expression[0]))};
    seperate(expression);
    n = operands.size();
    dp.resize(n, vector<vector<int>>(n));
    return f(0, n - 1);
}
int main() {
    cout << List(diffWaysToCompute("23+45-2*99-24+0"));
}