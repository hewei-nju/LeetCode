class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len == 0) {
            return false;
        }
        unordered_set<int> Aset;
        for (int i = 0; i <= len - 1; ++i) {
            if (Aset.size() > k) {
                Aset.erase(nums[i - k - 1]);
            }
            auto search = Aset.find(nums[i]);
            if (search != Aset.end()) {
                return true;
            } else {
                Aset.insert(nums[i]);
            }
        }
        return false;
        /** 超时
        for (int i = 0; i <= len - 1; ++i) {
            for (int j = 1; j <= k && (i+j) <= len - 1; ++j) {
                if (nums[i] == nums[i + j]) {
                    return true;
                }
            }
        }
        return false;
        */
    }
};