#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int reps = 1;
    int maxReps = 1;
    for(int i = 1; i < s.length(); i++) {
        if(s[i] != s[i - 1]) reps = 1;
        else reps += 1;
        maxReps = max(maxReps, reps);
    }
    cout << maxReps << endl;
    return 0;
}