#include <iostream>
#include <vector>
using namespace std;

/*
Alice and Bob are playing a fantasy battle game consisting of n rounds where
they summon one of three magical creatures each round: a Fire Dragon, a Water
Serpent, or an Earth Golem. In each round, players simultaneously summon their
creature and are awarded points as follows:
- If one player summons a Fire Dragon and the other summons an Earth Golem,
  the player who summoned the Fire Dragon is awarded a point.
- If one player summons a Water Serpent and the other summons a Fire Dragon,
  the player who summoned the Water Serpent is awarded a point.
- If one player summons an Earth Golem and the other summons a Water Serpent,
  the player who summoned the Earth Golem is awarded a point.
- If both players summon the same creature, no player is awarded a point.

You are given a string s consisting of n characters 'F', 'W', and 'E', representing
the sequence of creatures Alice will summon in each round:

If s[i] == 'F', Alice summons a Fire Dragon.
If s[i] == 'W', Alice summons a Water Serpent.
If s[i] == 'E', Alice summons an Earth Golem.

Bob’s sequence of moves is unknown, but it is guaranteed that Bob will never summon
the same creature in two consecutive rounds. Bob beats Alice if the total number of
points awarded to Bob after n rounds is strictly greater than the points awarded to
Alice.

Return the number of distinct sequences Bob can use to beat Alice.
Since the answer may be very large, return it modulo 109 + 7.
*/

int solve(string& s, vector<vector<vector<int>>>& dp,
int index, int move, int bob) {
    if(index == s.length()) return bob > 0;
    if(dp[index][move][bob + 1000] != -1)
        return dp[index][move][bob + 1000];
    int poss = 0;
    int F, W, E;

    switch(move) {
    case 0:
        F = (s[index] == 'F') ? solve(s, dp, index + 1, 1, bob) :
            ((s[index] == 'W') ? solve(s, dp, index + 1, 1, bob - 1) :
            solve(s, dp, index + 1, 1, bob + 1));
        W = (s[index] == 'W') ? solve(s, dp, index + 1, 2, bob) :
            ((s[index] == 'E') ? solve(s, dp, index + 1, 2, bob - 1) :
            solve(s, dp, index + 1, 2, bob + 1));
        E = (s[index] == 'E') ? solve(s, dp, index + 1, 3, bob) :
            ((s[index] == 'F') ? solve(s, dp, index + 1, 3, bob - 1) :
            solve(s, dp, index + 1, 3, bob + 1));
        poss = ((F + W) % 1000000007 + E) % 1000000007;
        break;

    case 1:
        W = (s[index] == 'W') ? solve(s, dp, index + 1, 2, bob) :
        ((s[index] == 'E') ? solve(s, dp, index + 1, 2, bob - 1) :
        solve(s, dp, index + 1, 2, bob + 1));
        E = (s[index] == 'E') ? solve(s, dp, index + 1, 3, bob) :
        ((s[index] == 'F') ? solve(s, dp, index + 1, 3, bob - 1) :
        solve(s, dp, index + 1, 3, bob + 1));
        poss = (W + E) % 1000000007;
        break;

    case 2:
        F = (s[index] == 'F') ? solve(s, dp, index + 1, 1, bob) :
        ((s[index] == 'W') ? solve(s, dp, index + 1, 1, bob - 1) :
        solve(s, dp, index + 1, 1, bob + 1));
        E = (s[index] == 'E') ? solve(s, dp, index + 1, 3, bob) :
        ((s[index] == 'F') ? solve(s, dp, index + 1, 3, bob - 1) :
        solve(s, dp, index + 1, 3, bob + 1));
        poss = (F + E) % 1000000007;
        break;

    case 3:
        F = (s[index] == 'F') ? solve(s, dp, index + 1, 1, bob) :
            ((s[index] == 'W') ? solve(s, dp, index + 1, 1, bob - 1) :
            solve(s, dp, index + 1, 1, bob + 1));
        W = (s[index] == 'W') ? solve(s, dp, index + 1, 2, bob) :
            ((s[index] == 'E') ? solve(s, dp, index + 1, 2, bob - 1) :
            solve(s, dp, index + 1, 2, bob + 1));
        poss = (F + W) % 1000000007;
        break;
    }
    return dp[index][move][bob + 1000] = poss;
}
int countWinningSequences(string s) {
    int n = s.length();
    vector<vector<vector<int>>>
    dp(n, vector<vector<int>>
    (4, vector<int>(1000 + n + 1, -1)));
    return solve(s, dp, 0, 0, 0);
}

int main() {
    string s = "EEFWEWWFFFWEEWEFFEEEFEFEEFWFEWEFEWWWFFEEEFFFE";
    cout << countWinningSequences(s);
    return 0;
}