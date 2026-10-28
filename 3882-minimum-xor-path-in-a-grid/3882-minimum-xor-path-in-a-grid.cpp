#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[r][c] stores the set of all possible XOR sums reachable at cell (r, c)
        std::vector<std::vector<std::unordered_set<int>>> dp(m, std::vector<std::unordered_set<int>>(n));
        
        // Base case: top-left cell
        dp[0][0].insert(grid[0][0]);
        
        // Fill the first row
        for (int c = 1; c < n; ++c) {
            int val = grid[0][c];
            for (int prev_xor : dp[0][c - 1]) {
                dp[0][c].insert(prev_xor ^ val);
            }
        }
        
        // Fill the first column
        for (int r = 1; r < m; ++r) {
            int val = grid[r][0];
            for (int prev_xor : dp[r - 1][0]) {
                dp[r][0].insert(prev_xor ^ val);
            }
        }
        
        // Fill the rest of the grid
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                int val = grid[r][c];
                // Collect from top neighbor
                for (int prev_xor : dp[r - 1][c]) {
                    dp[r][c].insert(prev_xor ^ val);
                }
                // Collect from left neighbor
                for (int prev_xor : dp[r][c - 1]) {
                    dp[r][c].insert(prev_xor ^ val);
                }
            }
        }
        
        // Find and return the minimum reachable XOR value at the destination (m - 1, n - 1)
        int min_val = 1500; 
        for (int xor_val : dp[m - 1][n - 1]) {
            min_val = std::min(min_val, xor_val);
        }
        
        return min_val;
    }
};