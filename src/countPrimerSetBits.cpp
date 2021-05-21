#include <iostream>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ret = 0;
        int cnt = 0;
        while (left <= right) {
            int tmp = left;
            while (left != 0) {
                if (left & 1 == 1)
                    cnt += 1;
                left >>= 1;
            }
            ret += isPrimer(cnt) ? 1: 0;
            cnt = 0;
            left = tmp + 1;
        }
        return ret;
    }

    bool isPrimer(int n) {
        return n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19 || n == 23 || n == 29 || n == 31;
    }
};

int main()
{
    Solution s;
    cout << s.countPrimeSetBits(6, 10) << endl;
}