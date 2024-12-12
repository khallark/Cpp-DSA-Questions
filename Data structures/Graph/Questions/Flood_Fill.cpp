#include <matrix.h>
#include <queue>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size(), n = image[0].size();
    int prev = image[sr][sc];
    if (prev == color) return image;
    queue<vector<int>> q;
    q.push({sr, sc});
    vector<vector<int>> dirs = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    while(!q.empty()) {
        vector<int> temp = q.front();
        q.pop();
        int i = temp[0], j = temp[1];
        image[i][j] = color;
        for(auto k : dirs) {
            int ni = i + k[0], nj = j + k[1];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && image[ni][nj] == prev) {
                q.push({ni, nj});
            }
        }
    }
    return image;
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    cout << floodFill(image, 1, 1, 2);
    return 0;
}