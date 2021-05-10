class Solution {
public:
    int maximumSwap(int num) {
        int tmp = num;
        int maxNum = num % 10;
        num /= 10;
        int maxAdd = 0;
        int maxbase = 1;
        int base = 1;
        while (num != 0) {
            base *= 10;
            if (maxNum < num % 10) {
                maxNum = num % 10;
                maxbase = base;
            } else {
                int add = (maxNum - num % 10) * base - (num % 10 - maxNum) * maxbase;
                maxAdd = max(maxAdd, add);
            }
            num /= 10;
        }
        return maxAdd + tmp;
    }
};