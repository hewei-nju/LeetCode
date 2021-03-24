#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int maxLen = 0;
        int last = -1;
        for (int cnt = 0; cnt <= 31; ++cnt) {
            if (n & 1 == 1) {
                if (last >= 0) {
                    maxLen = max(maxLen, cnt - last);
                }
                last = cnt;
            }
            n = n >> 1;
        }
        return maxLen;
    }
};


int main()
{
    Solution solution;
    cout << solution.binaryGap(5) << endl;
}