class Solution {
public:
    int row, col;
    bool vis[510][510];
    vector<int> dx = {0, 1, -1, 0};
    vector<int> dy = {1, 0, 0, -1};
    bool isValid(int x, int y) {
        return x >= 0 and x < row and y >= 0 and y < col;
    }
    void bfs(int x, int y, vector<vector<int>>& grid) {
        vis[x][y] = 1;
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            pair<int, int> u = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int a = u.first + dx[i], b = u.second + dy[i];
                if (isValid(a, b) and grid[a][b] and !vis[a][b]) {
                    vis[a][b] = 1;
                    q.push({a, b});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        for (int i = 0; i < col; i++) {
            if (grid[0][i]) {
                bfs(0, i, grid);
            }
            if (!vis[row - 1][i] and grid[row - 1][i]) {
                bfs(row - 1, i, grid);
            }
        }
        for (int i = 0; i < row; i++) {
            if (!vis[i][0] and grid[i][0]) {
                bfs(i, 0, grid);
            }
            if (!vis[i][col - 1] and grid[i][col - 1]) {
                bfs(i, col - 1, grid);
            }
        }
        int res = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!vis[i][j] and grid[i][j]) res++;
            }
        }
        return res;
    }
};


