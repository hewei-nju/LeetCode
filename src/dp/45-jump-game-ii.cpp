class Solution {
public:
    // 麻了！我是题解缝合怪!
    // 这题是我看题解理解后才写的！太菜了，提交了6次，淦！
    int jump(vector<int>& nums)
    {
        int maxPos = 0, end = 0, step = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            maxPos = std::max(maxPos, i + nums[i]);
            if (i == end) {
                end = maxPos;
                ++step;
            }
        }

        return step;
    }
};
