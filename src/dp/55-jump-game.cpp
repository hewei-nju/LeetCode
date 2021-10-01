class Solution {
public:
    // 思路：判断给定的数组中最大能去的点，判断这个点是否大于等于目标点即可！
    // dp[i] = std::max(dp[i-1], i+nums[i]);
    bool canJump(vector<int>& nums) {
        assert(nums.size() > 0);
        if (nums.size() == 1)
            true;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = dp[i-1] >= i ? std::max(dp[i - 1], i + nums[i]) : 0;
        }
        return dp[dp.size() - 1] >= dp.size()-1;
    }
};