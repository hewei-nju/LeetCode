class Solution {
public:
    bool IsPalindromic(const string& s, int i, int j)
    {
        if (i == j)
            return true;
        int len = j - i + 1;
        int mid = (i + j) / 2;
        int left = (len & 1) ? mid - 1 : mid;
        int right = mid + 1;

        while (left >= i && right <= j) {
            if (s[left] != s[right])
                return false;
        }
        return true;
    }

    string longestPalindrome(string s)
    {
        if (s.size() <= 1)
            return s;

        int beg = 0, maxLen = 1;
        bool dp[s.size()][s.size()];
        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = true;
        }

        for (int len = 2; len <= s.size(); ++len) {
            for (int i = 0; i < s.size(); ++i) {
                int j = len + i - 1;
                if (j >= s.size())
                    break;
                if (s[i] != s[j])
                    dp[i][j] = false;
                else {
                    if (j - i < 3)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    beg = i;
                }
            }
        }
        return s.substr(beg, maxLen);
    }
};