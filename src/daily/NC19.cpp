// 连续数组的最大子序列和

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> a) {
        int lastMax = 0;
        int maxSum = a[0];
        
        for (int i = 0; i < a.size(); i++) {
            lastMax += a[i];
            if (lastMax > maxSum) {
                maxSum = lastMax;
            }
            if (lastMax < 0) {
                lastMax = 0;
            }
        }
        return maxSum;
    }
};