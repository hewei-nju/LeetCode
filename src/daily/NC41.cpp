/*
给定一个数组arr，返回arr的最长无重复元素子数组的长度，无重复指的是所有数字都不相同。
子数组是连续的，比如[1,3,5,7,9]的子数组有[1,3]，[3,5,7]等等，但是[1,3,7]不是子数组

数据范围：0≤∣arr∣≤1000000，0 < arr[i] <= 100000
​	
 ≤100000
要求：空间复杂度 O(n)，时间复杂度 O(nlogn)
*/


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        // write code here
        // <num,idx>
        unordered_map<int, int> hsmap;
        int start = 0, end = 0;
        int maxLen = 1;
        for (int i = 0; i < arr.size(); ++i) {
            if (hsmap.find(arr[i]) == hsmap.end()) {
                hsmap.insert({arr[i], i});
            } else {
                if (start <= hsmap[arr[i]])
                    start = hsmap[arr[i]] + 1;
                hsmap[arr[i]] = i;
            }
            if (end - start + 1 > maxLen) {
                maxLen = end - start + 1;
            }
            end += 1;
        }
        return maxLen;
    }
};

int main()
{
    vector<int> v { 3, 3, 2, 1, 3, 3, 3, 1 };
    Solution s;
    s.maxLength(v);
}