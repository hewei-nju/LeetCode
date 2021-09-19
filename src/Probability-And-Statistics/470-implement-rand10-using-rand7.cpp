// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    // 思路：其实思想很明确，就是用rand7来凑成一个概率相等的rand10
    // 然后我的想法和这个题解有些类似，但是我没完全想对！
    // 所以直接抄了题解，链接为：https://leetcode-cn.com/problems/implement-rand10-using-rand7/solution/mo-neng-gou-zao-fa-du-li-sui-ji-shi-jian-9xpz/
    int rand10()
    {
        int first, second;
        while ((first = rand7()) > 6)
            ;
        while ((second = rand7()) > 5)
            ;
        return (first & 1) == 1 ? second : 5 + second;
    }
};