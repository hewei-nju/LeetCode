/*
请实现有重复数字的升序数组的二分查找
给定一个 元素有序的（升序）长度为n的整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的第一个出现的target，如果目标值存在返回下标，否则返回 -1

数据范围：
进阶：时间复杂度O(logn)，空间复杂度O(n)
*/

// 注意lower_bound表示第一个不大于target的位置
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 如果目标值存在返回下标，否则返回 -1
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(vector<int>& nums, int target)
    {
        // write code here
        auto iter = lower_bound(nums.begin(), nums.end(), target);
        if (iter == nums.end() || *iter != target)
            return -1;
        return iter - nums.begin();
    }
};