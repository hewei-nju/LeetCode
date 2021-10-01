class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        if (nums.size() == 3)
            return max(nums[1], nums[0] + nums[2]);
        nums[2] += nums[0];
        for (int i = 3; i <= nums.size() - 1; ++i)
            nums[i] = max(nums[i - 2], nums[i - 3]) + nums[i];
        int ret = 0;
        for (int i = 0; i <= nums.size() - 1; ++i)
            ret = max(ret, nums[i]);
        return ret;
    }
};