class Solution {
public:
    // 超时
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int len = nums.size();
        vector<int> ret;
        vector<int> xorSum(len, nums[0]);
        int i = 1;
        while (i < len) {
            xorSum[i] = nums[i - 1] ^ nums[i];
            ++i;
        }

        for (auto vec: queries) {
            i = 0;
            int ans = -1;
            while (i < len) {
                vec[0] ^= xorSum[i];
                if (nums[i] <= vec[1])
                    ans = max(ans, vec[0]);
                ++i;
            }
            ret.push_back(ans);
        }
        return ret;
    }
};

