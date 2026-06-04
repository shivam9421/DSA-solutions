class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        int total_squares = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If it's a 1 and not on the top or left border
                if (matrix[i][j] == 1 && i > 0 && j > 0) {
                    matrix[i][j] = 1 + std::min({
                        matrix[i-1][j],     // Top
                        matrix[i][j-1],     // Left
                        matrix[i-1][j-1]    // Top-Left
                    });
                }
                
                // Add the size (which equals the number of squares ending here) to the total
                total_squares += matrix[i][j];
            }
        }
        
        return total_squares;
        
    }
};