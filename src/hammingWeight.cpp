class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n != 0) {
            ret += 0x00000001 & n;
            n >>= 1;
        }
        return ret;
    }
};