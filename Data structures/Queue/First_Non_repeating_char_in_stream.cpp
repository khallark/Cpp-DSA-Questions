#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
string FirstNonRepeating(string A) {
	unordered_map<char, int> m;
    queue<char> q;
    string ans = "";
    for(int i = 0; i < A.length(); i++) {
        if(m[A[i]] == 0) {
            q.push(A[i]);
            m[A[i]]++;
        }
        else if(A[i] == q.front()) {
            m[A[i]]++;
            while(!q.empty() && m[q.front()] > 1) {
                q.pop();
            }
        }
        else {
            m[A[i]]++;
        }
        if(!q.empty()) {
            ans.push_back(q.front());
        }
        else {
            ans.push_back('#');
        }
    }
    return ans;
}
int main() {
    string A = "aaaaaaaaaaaaaabaaaaaaaabcaaaaaaaaa";
    cout << FirstNonRepeating(A) << endl;
    return 0;
}