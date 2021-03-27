class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = 0, pos2 = 0;
        while (pos1 <= m - 1 && pos2 <= n - 1) {
            if (nums1[pos1] > nums2[pos2]) {
                int tmp = nums1[pos1];
                nums1[pos1] = nums2[pos2];
                int i = pos2 + 1;
                while (i <= n - 1 && tmp > nums2[i]) {
                    nums2[i - 1] = nums2[i];
                    ++i;
                }
                nums2[i - 1] = tmp;
            } else {
                ++pos1;
            }
        }
        while (pos2 <= n - 1) {
            nums1[pos1++] = nums2[pos2++];
        }
    }
};

