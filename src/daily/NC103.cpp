/*
写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）

数据范围： 0≤n≤1000
要求：空间复杂度 O(n)，时间复杂度 )O(n)
*/


class Solution {
public:
    /**
     * 反转字符串
     * @param str string字符串 
     * @return string字符串
     */
    string solve(string str) {
        // write code here
        reverse(str.begin(), str.end());
        return str;
    }
};