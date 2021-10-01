class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        int size = nums.size();
        for (int i = 0; i <= size - 1; ++i) {
            if (nums[i] != val) {
                nums[len++] = nums[i];
            }
        }
        return len;
    }
};