class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() <= 1) {
            return true;
        }
        int cnt = 0;
        for (int i = 0; i <= nums.size() - 2; ++i) {
            if (nums[i] > nums[i + 1]) {
                if (i == 0 || nums[i + 1] >= nums[i - 1]) {
                    nums[i] = nums[i + 1];
                } else {
                    nums[i + 1] = nums[i];
                }
                cnt += 1;
            }
            if (cnt >= 2) {
                return false;
            }
        }
        return true;
    }
};