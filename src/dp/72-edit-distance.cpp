class Solution {
public:
    int minDistance(string word1, string word2)
    {
        if (word2.size() == 0)
            return word1.size();
        if (word1.size() == 0)
            return word2.size();

        // dp[i][j]：word1.size() == i & word2.size() == j时，word1变换为word2需要的最小操作次数
        // 很明显，dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
        int dp[word1.size() + 1][word2.size() + 1];
        dp[0][0] = 0;
        for (int i = 1; i <= word1.size(); ++i) {
            dp[i][0] = dp[i - 1][0] + 1;
        }

        for (int i = 1; i <= word2.size(); ++i) {
            dp[0][i] = dp[0][i - 1] + 1;
        }

        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};