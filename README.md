# LeetCode



#### 27-移除元素：
`Line 1034: Char 9: runtime error: reference binding to null pointer of type 'int' (stl_vector.h)`

报错代码
```C++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        for (int i = 0; i <= nums.size() - 1; ++i) {
            if (nums[i] != val) {
                nums[len++] = nums[i];
            }
        }
        return len;
    }
};
``` 
> 报错原因： vector的size()操作返回的是一个**无符号**整数，当nums为空时，size()返回0，**-1**后就变成一个更大的数，从而进入循环进行不可行操作。

```C++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        int size = nums.size();
        for (int i = 0; i <= size - 1; ++i) {
            if (nums[i] != val) {
                nums[len++] = nums[i];
            }
        }
        return len;
    }
};

```


#### 搜索插入位置
> 这题难度倒是不大，就是一个变化的二分搜索，但是要注意它的边界问题，希望能够静下来思考清楚再进行coding，否则边界问题总在一点点的发现。


#### 101-对称二叉树:x:
#### TODO
> 这题我的思路是正确的，但是实现的时候没有考虑重新弄一个函数，导致写在一个函数里，debug一直有问题，就看了一眼题解，感觉很强！很淦！


#### 121-买卖股票的最佳时机
> 这题我是抄的题解！本身我想了双重循环的算法，但是太拉跨了！然后我其实觉得官方题解思路是错的！

> 我个人的理解：因为本身我们要求的是后面时间段对前面时间段股票价格做差的最大值。所以我们理应将这一串股票价格看成折线图，我们肯定是在每段的最低点进行买入，然后求后面这个最大差，如果出现了另一个更小值，我们肯定要转换，因为，如果后面有同前面最小值做差最大，那么同现在的更小值肯定更大，所以就这么流水线在线处理就行。