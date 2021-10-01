class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0, len = nums.size();
        for (; j <= len - 1 && i <= len - 1;) {
            if (nums[i] != 0) 
                ++i, ++j;
            else if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                ++i, ++j;
            } else
                ++j;
        }
    }
};