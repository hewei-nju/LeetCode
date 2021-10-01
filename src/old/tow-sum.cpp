#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        for (int i = 0; i <= nums.size() - 1; ++i) {
            for (int j = 0; j <= nums.size() - 1; ++j) {
                if (i != j && nums[i] + nums[j] == target) {
                    ans[0] = j, ans[1] = i;
                }
            }
        }
        return ans;
    }
};