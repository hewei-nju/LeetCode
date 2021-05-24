class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int ret = 0;
        int sum = 0;
        while (j < nums.size()) {
            sum += nums[j];
            ++j;
            while (sum >= target) {
                ret = ret == 0 ? j : min(ret, j - i);
                sum -= nums[i];
                i += 1;
            }
        }
        return ret;
    }
};

