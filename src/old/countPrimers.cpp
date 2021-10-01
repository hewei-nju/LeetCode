class Solution {
public:
    bool isPrimer(int num) {
        if (num <= 1) {
            return false;
        } else {
            if (num == 2 || num == 3) {
                return true;
            } else {
                for (int i = 2; i * i <= num; ++i) {
                    if (num % i == 0) {
                        return false;
                    }
                }
                return true;
            }
        }
    }
    int countPrimes(int n) {
        int cnt = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrimer(i)) {
                cnt += 1;
            }
        }
        return cnt;
    }
};