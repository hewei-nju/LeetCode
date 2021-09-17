class Solution {
public:
    // 思路：这题很简单呀！不就是求KMP的next数组嘛，O(n)复杂度！easy
    string longestPrefix(string s)
    {
        vector<int> next(s.size(), 0);
        for (int i = 1, j = 0; i < s.size(); ++i) {
            while (j > 0 && s[i] != s[j])
                j = next[j - 1];
            if (s[i] == s[j])
                j += 1;
            next[i] = j;
        }
        return s.substr(0, next[next.size() - 1]);
    }
};