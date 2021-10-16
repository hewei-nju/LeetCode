// 寻找第k大数
// 有O(n)算法，不过我还不会。

class Solution {
public:
    int findKth(vector<int> a, int n, int K)
    {
        // write code here
        sort(a.begin(), a.begin() + n, greater<int>());
        return a[K - 1];
    }
};