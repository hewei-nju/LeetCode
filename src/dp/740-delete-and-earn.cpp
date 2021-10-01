class Solution {
public:
    // 思路：这完全就是打家劫舍的变化版本鸭！
    int deleteAndEarn(vector<int>& nums)
    {
        int MAX = *max_element(nums.begin(), nums.end());
        if (MAX == 1)
            return nums[0];
        vector<int> scores(MAX + 1, 0);
        for (auto num: nums) {
            scores[num] += num;
        }

        vector<int> dp(MAX + 1, 0);
        dp[0] = scores[0];
        dp[1] = scores[1];
        for (int i = 2; i <= MAX; ++i) {
            dp[i] = std::max(dp[i - 1], scores[i] + dp[i - 2]);
        }
        return std::max(dp[MAX], dp[MAX - 1]);
    }
};

