class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int dp[grid.size()][grid[0].size()];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid[0].size(); ++i) {
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }
        for (int i = 1; i < grid.size(); ++i) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }

        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                dp[i][j] = std::min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};