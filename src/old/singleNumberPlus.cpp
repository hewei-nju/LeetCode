class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i <= 31; ++i) {
            int sum = 0;
            for (int j = 0; j <= nums.size() - 1; ++j) {
                sum += (nums[j] >> i) & 1;
            }
            ret ^= (sum % 3) << i;
        }
        return ret;
    }
};