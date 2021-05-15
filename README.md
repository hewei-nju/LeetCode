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

#### 137-只出现一次的数字II
> 这题又抄了题解！！！wwww，跪了，这个太强了


> 统计所有数字中每个位中1出现的总数，那么对于某个位，1出现的次数一定是3的倍数+1或0，那么对这个数%3得到的结果就是目的数字在该位上的值


#### 205-同构字符串
> 这题我的思路和题解一样，然后突然看到一个朋友的题解，贼强！！！，贴下面了

```c++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        for(int i = 0; i < s.size(); ++i)
            if(s.find(s[i]) != t.find(t[i]))
                return false;
        return true;
    }
};
```


#### 1143-最长公共子序列
> 这题直接抄的题解，我对动态规划的理解很浅薄！这个地方需要很多练习。

#### 47-全排列II
> TODO


#### 667-优美的排列II
>这道题很神奇，它是属于找规律的脑筋急转弯题目。

1. 因为我们有n个数，所以交叉差有n-1个，题目要求有且仅有k个不同的差，那么可以先弄出k个不同的差，然后再让后面的差同前面的差相同即可。
2. 我们知道，对于1-n，这n个不同的数，如1, n, 2, n-1, ..这种排列，肯定有n-1个互不相同的差。且差分别为n-1,n-2,...,1.
3. 所以我们可以先构造出k个差，然后构造出n-1-k个差为1即可，这不就是等差数组嘛？


#### 697-数组的度
> 这题很那啥，我是排序后统计的，事件复杂度不太行！呜呜呜！居然用的哈希表！淦


#### 1310-子数组异或查询
> 这题我用的最朴素的想法写的，然后过不了，O(nm)的时间复杂度，然后我其实一开始就知道肯定过不了，但是我在想怎么优化时，确实想了要不要将前面的所有进行分次异或！嗨，最终还是败给了自己懒于思考！
其实我觉得，我正常思考会是能做出这道题的，不需要看题解！我太懒了！

好的，回归题解！讲下我个人的分析：
1. 因为我们查询的结果是arr[queries[0]]->arr[queries[1]]的异或和，并且，queries[0] <= queries[1].
2. 不妨记queries[0]对应于arr[i], queries[1]对应于arr[j] (i < j).
3. ans = arr[i] ^ arr[i+1]^...^arr[j-1]^arr[j];
4. 所以我们可以令xor1 = arr[0]^arr[1]^...^arr[i-1];
5. 令xor2 = arr[0]^arr[1]^...^arr[i-1]^arr[i]^...^arr[j];
6. 所以ans = xor1 ^ xor2;
7. 所以就可以通过下标直接查找进行O(1)的计算了。

其实真的不难，为啥我就是不肯想呢？一定要改正这个坏习惯！思考！否则你刷题干嘛？


#### 1269-停在原地的方案数
1. 这题是一个简单的动态规划题，一开始我列出了动态转移方程，但是写代码时边界搞错了，很气！
2. 这题虽然是一道困难题目，但是我感觉似乎没有那么夸张？我没写对就是了！
3. dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];(因为一步有三种可能，当然，这里还要注意题目的需求就是了。我就是这里没搞出来！www)
4. 然后我看了题解后，发现非常巧妙！因为整个动态转移，我用i步走到当前位置的可能数，都等于我用了i-1步走了最多离我一步远的位置可能数(暂时不考虑边界)，也就是说它都只与前一步相关。因此，我们可以通过。
5. 一维动态规划，dp[i]表示走了dp[i]步到达i这个位置。于是我们想要知道dp[i] = dp[i] + dp[i-1] + dp[i+1]，我们就得知道走了dp[i]可能的次数了。
6. 因此，我们可以一个一维数组不断迭代，获取走了steps(1,-1,0都算一步)的各个位置的可能方案数。


#### 123-买股票的最佳时机III
1. /**
         * min1 max1 min2 max2 minT maxT
         * min1 < max1, max1 > min2, min2 < max2, max2 > minT, minT < maxT
         * max has five choices bellow:
         * min1 max1 min2 max2
         * min1 max1 min2 maxT
         * min1 max1 minT maxT
         * min1 max2 minT maxT
         * min2 max2 minT maxT
        */
2. 上面是我最初的算法，然后编写的代码能够过203/214个用例，但是，其实这个算法并不是严格正确的！比如用例如下：18,9305,107,9957,1,4303,131,9996,2,9214,1007,9972。
3. 正确解法：
```
1. 对于任何一天结束后，股民有一下几种选择：
    1. 没进行任何操作
    2. 进行了一次买
    3. 进行了一次卖
    4. 进行了第二次买
    5. 进行了第二次卖
2. 对于1.1，显然利润为0；不妨记上述其他四种的最大利润为b1,s1,b2,s2.
3. 则有b1 = max(b1, b1 - p); s1 = max(s1, b1 + p); b2 = max(b2, s1 - p); s2 = max(s2, b2 + p);
```
4. https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
5. https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
6. https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/


#### 309-最佳买卖股票时机含冷冻期
0. 设当天的三种最大收入分别为：buy为买进的最大收入，sell为卖出的最大收入，freeze为冷冻的最大收入
1. 对于第i天买进的最大收入buy = max(buy, freeze - p); // max中的buy和freeze都是前一天的记录
2. 对于第i天卖出的最大收入sell = max(sell, buy + p); // 同上
3. 对于第i天冷冻的最大收入freeze = sell; // 等于上次卖出的收入

#### 