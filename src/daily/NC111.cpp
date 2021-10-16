/*
给定一个长度为n的数组nums，数组由一些非负整数组成，现需要将他们进行排列并拼接，每个数不可拆分，使得最后的结果最大，返回值需要是string类型，否则可能会溢出。

数据范围：1 <= n <= 100, 0≤nums[i]≤10000
进阶：时间复杂度O(nlogn) ，空间复杂度：O(n)
*/

class Solution {
public:
    /**
     * 最大数
     * @param nums int整型vector 
     * @return string字符串
     */

    // 本来我一开始按照字典序排列做的，发现不对，然后调整了算法还是不太对。
    // 其实通过例子就能很好的察觉出算法：10 1 --> 110 vs 101
    // so，我们应该将字符串凭借比较！
    string solve(vector<int>& nums)
    {
        vector<string> strs;
        for (auto n : nums) {
            strs.emplace_back(to_string(n));
        }

        auto f = [](const string& lhs, const string& rhs) {
            return lhs + rhs < rhs + lhs;
        };
        sort(strs.begin(), strs.end(), f);

        string res;
        for (int i = strs.size() - 1; i >= 0; i--) {
            res += strs[i];
            if (res == "0")
                return res;
        }
        return res;
    }
};
