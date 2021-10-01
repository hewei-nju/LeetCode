class Solution {
public:
    // 思路：一开始想就是：对于当前位置的最大robber金额，肯定和前一个位置无关，因为不能触发报警，然后只要前两个就能覆盖所有的位置了！dp[i] =  max(dp[i-1], nums[i] + dp[i-2])；
    // 注意：首尾不能同时使用，因此可以分为两个区段进行，0~n-2, 1~n-1
    int getMaxFromRange(const vector<int>& nums, int start, int end) {
        int prev = nums[start], int cur = std::max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; ++i) {
            int tmp = cur;
            cur = std::max(tmp, prev + nums[i]);
            prev = tmp;
        }
        return cur;
    }
    int rob(vector<int>& nums)
    {
        assert(nums.size() > 0);
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return std::max(nums[0], nums[1]);
        return std::max(getMaxFromRange(nums, 0, nums.size() - 2), getMaxFromRange(nums, 1, nums.size() - 1));
    }
};
