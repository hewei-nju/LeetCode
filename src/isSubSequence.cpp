class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        int len1 = s.size();
        if (len1 == 0) {
            return true;
        }
        int len2 = t.size();
        while (i <= len2 - 1) {
            if (j == len1) {
                return true;
            }
            if (t[i] == s[j]) {
                j += 1;
            }
            ++i;
        }
        return j == len1;
    }
};