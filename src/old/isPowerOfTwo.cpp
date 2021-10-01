class Solution {
public:
    bool isPowerOfTwo(int n) {
        int t = n;
        int ret = 0;
        while (n > 0) {
            if ((n & 1) == 1)
                ret += 1;
            n >>= 1;
        }
        return ret < 2 && t > 0;
    }
};