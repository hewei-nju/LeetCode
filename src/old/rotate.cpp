class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        if (nums.size() == 0)
            return;
        k = k % nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
    /**3 翻转，这个我是抄的题解*/
    void reverse(vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }
    /* 2
        vector<int> tmp;
        for (int i = nums.size() - k; i <= nums.size() - 1; ++i)
            tmp.push_back(nums[i]);
        for (int i = 0; i < nums.size() - k; ++i)
            tmp.push_back(nums[i]);
        for (int i = 0; i <= nums.size() - 1; ++i)
            nums[i] = tmp[i];
        /* 1
            while (k > 0) {
            --k;
            int tmp = nums[nums.size() - 1];
            for (int i = nums.size(); i >= 1; --i) {
                nums[i] = nums[i - 1];
            }
            nums[0] = tmp;
        }*/
}
}
;