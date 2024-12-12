#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define pii pair<int, int>
#define pci pair<int, char>
using namespace std;

int main() {
    vector<int> m(26);
    string s;
    cin >> s;
    for(auto i : s) m[i - 'A']++;
    int odd_count = 0;
    char odd_char = '#';
    vector<pci> chars;
    for(int i = 0; i < 26; i++) {
        if(!m[i]) continue;
        if(m[i] & 1) {
            odd_char = i + 'A';
            odd_count++;
            if(odd_count > 1) break;
        }
        chars.push_back({m[i] / 2, i + 'A'});
    }
    sort(chars.begin(), chars.end());
    if(odd_count > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    string ans = "";
    for(int i = chars.size() - 1; i >= 0; i--) {
        if(chars[i].second != odd_char) {
            ans += string(chars[i].first, chars[i].second);
        }
    }
    if(odd_char != '#') {
        ans += string(m[odd_char - 'A'] / 2, odd_char);
    }
    s = ans;
    reverse(s.begin(), s.end());
    if(!odd_count) cout << ans + s << endl;
    else cout << ans + odd_char + s << endl;
    return 0;
}