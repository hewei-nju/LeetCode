class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ret = 0;
        int size = nums.size();
        int Len = 1;
        for (int i = 1; i <= size - 1; ++i) {
            if (nums[i] <= nums[i - 1]) {
                ret = max(ret, Len);
                Len = 0;
            }
            Len += 1;
        }
        ret = max(ret, Len);
        return ret;
    }
};