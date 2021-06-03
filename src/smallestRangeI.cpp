class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int max_n = INT_MIN;
        int min_n = INT_MAX;
        for (auto n: nums) {
            max_n = max_n < n ? n : max_n;
            min_n = min_n > n ? n : min_n;
        }
        return 0 > (max_n - min_n - 2*k) ? 0 : (max_n - min_n - 2*k);
    }
};
