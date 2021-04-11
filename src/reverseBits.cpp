class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        uint32_t povit = 0x80000000;
        while (n > 0) {
            ret += povit * (0x00000001 & n);
            povit >>= 1;
            n >>= 1;
        }
        return ret;
    }
};