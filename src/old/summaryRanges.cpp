class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if (nums.empty())
            return ret;
        int i = 0, j = 1;
        while (j <= nums.size() - 1) {
            if (nums[j] == nums[j - 1] + 1)
                ++j;
            else {
                if (j == i + 1) 
                    ret.push_back(to_string(nums[i]));
                else 
                    ret.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
                i = j;
                j += 1;
            }
        }
        if (j == nums.size()) 
            if (i == nums.size() - 1)
                ret.push_back(to_string(nums[i]));
            else 
                ret.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
        return ret;
    }
};