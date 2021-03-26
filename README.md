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