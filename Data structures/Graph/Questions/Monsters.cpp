#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
int n, m;
vector<vector<char>> grid;
vector<vector<int>> monster;
vector<vector<int>> player;
vector<vector<char>> player_dir;
vector<vector<int>> monster_pos;
vector<int> player_pos;
int ans = -1;
string path = "";

int row[] = {0, -1, 0, 1};
int col[] = {-1, 0, 1, 0};
char dir[] = {'L', 'U', 'R', 'D'};

void bfs_monster() {
    queue<vector<int>> q;
    for(auto i : monster_pos) {
        q.push({i[0], i[1]});
        monster[i[0]][i[1]] = 0;
    }
    while(!q.empty()) {
        vector<int> temp = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            int i = temp[0] + row[k], j = temp[1] + col[k];
            if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#' && monster[i][j] > monster[temp[0]][temp[1]] + 1) {
                monster[i][j] = monster[temp[0]][temp[1]] + 1;
                q.push({i, j});
            }
        }
    }
}

bool bfs_player() {
    queue<vector<int>> q;
    q.push({player_pos[0], player_pos[1]});
    player[player_pos[0]][player_pos[1]] = 0;
    while(!q.empty()) {
        vector<int> temp = q.front();
        q.pop();
        if(temp[0] == 0 || temp[0] == n - 1 || temp[1] == 0 || temp[1] == m - 1) {
            ans = player[temp[0]][temp[1]];
            int i = temp[0], j = temp[1];
            while(i != player_pos[0] || j != player_pos[1]) {
                path += player_dir[i][j];
                if(player_dir[i][j] == 'L') j++;
                else if(player_dir[i][j] == 'R') j--;
                else if(player_dir[i][j] == 'U') i++;
                else if(player_dir[i][j] == 'D') i--;
            }
            reverse(path.begin(), path.end());
            return true;
        }
        for(int k = 0; k < 4; k++) {
            int i = temp[0] + row[k], j = temp[1] + col[k];
            if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#' && player[temp[0]][temp[1]] + 1 < player[i][j] &&
            player[temp[0]][temp[1]] + 1 < monster[i][j]) {
                player_dir[i][j] = dir[k];
                player[i][j] = player[temp[0]][temp[1]] + 1;
                q.push({i, j});
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    grid = player_dir = vector<vector<char>>(n, vector<char>(m, 'W'));
    monster = player = vector<vector<int>>(n, vector<int>(m, INT_MAX));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'M') monster_pos.push_back({i, j});
            if(grid[i][j] == 'A') player_pos = {i, j};
        }
    }
    bfs_monster();
    if(bfs_player()) cout << "YES" << endl << ans << endl << path;
    else cout << "NO" << endl;
    return 0;
}