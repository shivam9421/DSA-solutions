class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int count = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 0 && !vis[r][c]) {
                    queue<pair<int, int>> q;
                        q.push({r, c});
                        vis[r][c] = 1 ;
                        bool isClosed = true;
                        while (!q.empty()) {
                        auto it = q.front();
                        q.pop();
                        int row = it.first;
                        int col = it.second;
                        if (row == 0 || row == grid.size() - 1 || col == 0 || col == grid[0].size() - 1) {
                            isClosed = false;
                        }
                        for (int i = 0; i < 4; i++) {
                            int nrow = drow[i] + row;
                            int ncol = dcol[i] + col;
                            if (nrow >= 0 && ncol >= 0 && nrow < grid.size() &&
                                    ncol < grid[0].size() &&
                                    vis[nrow][ncol] == 0 &&
                                    grid[nrow][ncol] ==0 ) {
                                        vis[nrow][ncol]=1;
                                q.push( {nrow, ncol});
                            }
                        }
                    }
                    if(isClosed)count++;
                }
            }
        }
        return count;
    }
};