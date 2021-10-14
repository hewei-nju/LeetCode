class Solution {
    // 思路：最大子序列和
    // 1. 目标最大和在中间：最大子序列和
    // 2. 目标最大和在两边：总和 - 最小子序列和
    // 3. 全负数：最小子序列和 == 总和，取最小值
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        int lastMax = nums[0];
        int lastMin = nums[0];
        int maxSub = nums[0];
        int minSub = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum += nums[i];
            if (lastMax >= 0)
                lastMax += nums[i];
            else
                lastMax = nums[i];
            if (lastMin <= 0)
                lastMin += nums[i];
            else
                lastMin = nums[i];
            if (lastMax > maxSub)
                maxSub = lastMax;
            if (lastMin < minSub)
                minSub = lastMin;
        }

        return sum - minSub == 0 ? maxSub : std::max(sum - minSub, maxSub);
    }
};