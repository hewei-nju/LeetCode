class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret = 0;
        while (x != y) {
            ret += (x & 0x00000001) ^ (y & 0x00000001);
            x >>= 1;
            y >>= 1;
        }
        return ret;
    }
};