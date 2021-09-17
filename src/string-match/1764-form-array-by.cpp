#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 思路：其实这题没想到什么好的思路，就是暴力模拟？
    // 说实话！我题目意思的理解了好几遍，”数组“这个概念和我理解的有点出入，它这个是完全连续的子序列！
    // 写到这里突然想起另外的方法：就普通的双指针吧！每次前一个groups中的数组，然后一次往后此长度后查询即可！
    bool equal(const vector<int>& a, const vector<int>& b, int beg)
    {
        if (b.size() - beg < a.size())
            return false;
        for (int i = 0; i < a.size(); ++i)
            if (a[i] != b[beg++])
                return false;
        return true;
    }
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums)
    {
        int i, j;
        for (i = 0, j = 0; i < groups.size(); ) {
            while (groups[i].size() > 0 && j < nums.size() && nums[j] != groups[i][0])
                ++j;
            if (j >= nums.size())
                return false;
            if (equal(groups[i], nums, j)) {
                j += groups[i].size();
                ++i;
            } else
                ++j;
        }
        return i == groups.size();
    }
};


int main()
{
    vector<vector<int>> g { { 6636698, 4693069, -2178984, -2253405, -2732131, 8550889, -2324014, -2561263 }, { -8973571, -9146179, 7704305, -1063430, -6569826 }, { 2791091 }, { -9691134, 651171, 9835817, 4163881, 4944714, 8166788, -9025553, -9250995, 1599781 } };
    vector<int> n{8550889,-2178984,6636698,4693069,-2178984,-2253405,-2732131,8550889,-2324014,-2561263,-2324014,8550889,-8973571,-9146179,7704305,-1063430,-6569826,2791091,-9691134,651171,9835817,4163881,4944714,8166788,-9025553,-9250995,1599781};

    Solution s;
    cout << s.canChoose(g, n);
}