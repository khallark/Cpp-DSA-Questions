#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

char grid[1000][1000];
char dirs[1000][1000];
int vis[1000][1000];
string path = "";
int n, m;

bool bfs(int si, int sj) {
    queue<vector<int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while(!q.empty()) {
        vector<int> temp = q.front();
        int i = temp[0], j = temp[1];
        q.pop();
        if(grid[i][j] == 'B') {
            while (!(i == si && j == sj)) {
                path += dirs[i][j];
                if (path.back() == 'L') j++;
                if (path.back() == 'R') j--;
                if (path.back() == 'U') i++;
                if (path.back() == 'D') i--;
            }
            reverse(path.begin(), path.end());
            return true;
        }
        int row[] = {0, -1, 0, 1};
        int col[] = {-1, 0, 1, 0};
        char dir[] = {'L', 'U', 'R', 'D'};
        for(int k = 0; k < 4; k++) {
            int I = i + row[k];
            int J = j + col[k];
            if(I >= 0 && I < n && J >= 0 && J < m && (grid[I][J] == '.' || grid[I][J] == 'B') && !vis[I][J]) {
                q.push({I, J});
                vis[I][J] = true;
                dirs[I][J] = dir[k];
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    int si, sj;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') si = i, sj = j;
        }
    }
    if(bfs(si, sj)) {
        cout << "YES" << endl << path.length() << endl << path << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}