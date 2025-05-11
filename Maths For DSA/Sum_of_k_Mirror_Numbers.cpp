// https://leetcode.com/problems/sum-of-k-mirror-numbers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> nums;
int K;

void addIfPalindrome(string s) {
    long long num = stoll(s);
    long long temp = num;
    string ans = "";
    while(num >= 1) {
        ans += char('0' + (num % K));
        num /= K;
    }
    reverse(ans.begin(), ans.end());
    int l = 0, r = ans.length() - 1;
    while(l < r) {
        if(ans[l] != ans[r]) return;
        l++, r--;
    }
    nums.push_back(temp);
}
void f(string num, int l, int r) {
    for(char i = num[l]; i <= '9'; i++) {
        num[l] = num[r] = i;
        if(l == r || r - l == 1) addIfPalindrome(num);
        else f(num, l + 1, r - 1);
    }
}
long long kMirror(int k, int n) {
    K = k;
    int i = 1;
    while(nums.size() < n) {
        string num(i, '0');
        num[0] = num[i - 1] = '1';
        f(num, 0, i - 1);
        i++;
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans += nums[i];
    }
    return ans;
}

int main() {
    cout << kMirror(2, 30);
    return 0;
}