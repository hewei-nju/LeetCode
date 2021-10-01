
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 思路：f(x, n-1)表示n-1颗色子抛出x的总和的概率，则f(x, n) = 1/6(f(x-1, n-1) + f(x-2, n-1) + f(x-3, n-1) + f(x-4, n-1) + f(x-5, n-1) + f(x-6, n-1)); 即动态规划即可！
    vector<double> dicesProbability(int n)
    {
        vector<double> prev { 1.0 / 6, 1.0 / 6, 1.0 / 6, 1.0 / 6, 1.0 / 6, 1.0 / 6 };
        vector<double> next;
        for (int i = 2; i <= n; ++i) {
            next = vector<double>(5 * i + 1, 0);
            for (int j = i; j <= 6 * i; ++j) {
                for (int k = j - 6; k <= j - 1 && k <= (i - 1) * 6; k += 1) {
                    if (k >= i - 1)
                        next[j - i] += 1.0 / 6 * prev[k - (i - 1)];
                }
            }
            prev = next;
        }
        return prev;
    }
};

int main()
{
    Solution s;
    s.dicesProbability(2);
}