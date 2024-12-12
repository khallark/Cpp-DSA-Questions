#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
int distinctSubsequences(string &str, string &sub)
{
	vector<int> prev(str.length() + 1, 1);
	vector<int> curr(str.length() + 1, 0);
	for(int i = 1; i <= sub.length(); i++) {
		for(int j = 1; j <= str.length() ; j++) {
			if(sub[i - 1] == str[j - 1]) {
				curr[j] = (curr[j - 1] + prev[j - 1]) % MOD;
			}
			else curr[j] = curr[j - 1];
		}
		prev = curr;
	}

	return prev[str.length()];
}

int main() {
    string str = "dingdingdingding";
    string sub = "ing";
    cout << distinctSubsequences(str, sub);
    return 0;
}