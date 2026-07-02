class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                vis[0][j] = 1;
                q.push({0, j});
            }
            if (grid[m - 1][j] == 1) {
                vis[m - 1][j] = 1;
                q.push({m-1, j});
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                vis[i][0] = 1;
                q.push({i, 0});
            }
            if (grid[i][n - 1] == 1) {
                vis[i][n - 1] = 1;
                q.push({i, n - 1});
            }
        }
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if ((nrow >= 0 && ncol >= 0 && nrow < m && ncol < n) &&
                    (grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0)) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        int cnt=0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0 && grid[i][j] == 1){
                    cnt++;
                }
                  
            }
        }
        return cnt;
    }
};