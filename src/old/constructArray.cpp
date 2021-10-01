class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret;
        int i = 0;
        for (i = 0; i < n - k - 1; ++i) {
            ret.push_back(i + 1);
        }
        int left = n - k, right = n;
        bool RIGHT = false;
        while (i < n) {
            if (RIGHT) {
                ret.push_back(right--);
                RIGHT = false;
            } else {
                ret.push_back(left++);
                RIGHT = true;
            }
            ++i;
        }
        return ret;
    }
};