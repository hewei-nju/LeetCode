/*
给定一个长度为 n 的可能有重复值的数组，找出其中不去重的最小的 k 个数。例如数组元素是4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4(任意顺序皆可)。
数据范围：0≤k,n≤10000，数组中每个数的大小0≤val≤1000
要求：空间复杂度 O(n) ，时间复杂度 O(nlogn)
*/


class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(), input.end());
        vector<int> res(input.begin(), input.begin() + k);
        return res;
    }
};