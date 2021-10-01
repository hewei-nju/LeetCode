class Solution {
public:
    // 思路：想了很久，都没有好的方法！我直接裂开！
    // 理解题解后写的！
    // 4 0
    // 3 1
    // 2 2
    // 1 3
    // dp[i][j]：表示还剩下i的A，j的B时的概率
    // dp[i][j] = 0.25*(dp[i-4][j] + dp[i-3][j-1] + dp[i-2][j-2] + dp[i-1][j-3])
    // dp[i][j] = 
    double soupServings(int n)
    {
        if (n > 4800)
            return 1;
        
    }
};