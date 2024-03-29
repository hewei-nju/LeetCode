#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int tmp = x % 10;
            x /= 10;
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && tmp > 7)) {
                return 0;
            } else if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && tmp < -8)) {
                return 0;
            } else {
                ans = ans * 10 + tmp;
            }
        }
        return ans;
    }
};