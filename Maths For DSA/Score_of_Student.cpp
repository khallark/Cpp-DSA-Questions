#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
using namespace std;

string S;
vector<int> nums;
vector<char> ops;
unordered_map<string, unordered_set<int>> memo;
int n;
unordered_set<int> f(int l, int r) {
    string key = to_string(l) + ',' + to_string(r);
    if(memo.count(key)) return memo[key];

    unordered_set<int> res;

    if(l == r) {
        if(nums[l] <= 1000) {
            res.insert(nums[l]);
            return memo[key] = res;
        }
    }

    for(int k = l; k < r; k++) {
        unordered_set<int> leftSet = f(l, k);
        unordered_set<int> rightSet = f(k + 1, r);
        for(auto left : leftSet) {
            for(auto right : rightSet) {
                int ans = ops[k] == '+' ?
                    left + right :
                    left * right;
                if(ans <= 1000) res.insert(ans);
            }
        }
    }

    return memo[key] = res;
}
int scoreOfStudents(string s, vector<int>& answers) {
    n = s.length();
    for(int i = 0; i < n; i+=2)
        nums.push_back(int(s[i]) - '0');
    for(int i = 1; i < n; i+=2)
        ops.push_back(s[i]);

    unordered_set<int> possibles = f(0, nums.size() - 1);

    vector<int> ns;
    int i = 0;
    while(i < nums.size()) {
        int ans = nums[i];
        while(i < nums.size() - 1 && ops[i] == '*') {
            ans *= nums[++i];
        }
        ns.push_back(ans);
        i++;
    }
    int right = accumulate(ns.begin(), ns.end(), 0);

    int ans = 0;
    for(auto i : answers) {
        if(i == right) ans += 5;
        else if(possibles.find(i) != possibles.end()) ans += 2;
    }
    return ans;
}

int main() {
    string s = "3+5*2";
    vector<int> answers = {13,0,10,13,13,16,16};
    cout << scoreOfStudents(s, answers);
    return 0;
}