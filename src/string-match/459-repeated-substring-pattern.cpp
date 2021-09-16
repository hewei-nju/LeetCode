class Solution {
public:
    bool repeatedSubstringPattern(string s)
    {
        if (s.size() == 0)
            return true;
        int beg = 0, end = 0;
        for (int i = 1; i < s.size(); ++i) {
            // s[i] == s[beg]：可能是重复子字符串
            if (s[i] == s[beg]) {
                end = i;
                // 总体字符串长度是否能整除本子字符串长度
                if (s.size() % (end - beg) != 0) {
                    continue;
                }
                int j;
                for (j = i; j < s.size(); ++j) {
                    if (s[j] != s[(beg + j - i) % (end - beg)]) {
                        break;
                    }
                }
                if (j == s.size())
                    return true;
            }
        }
        return false;

        // 答案区里看到的更巧妙的方法：
        // return (s + s).substr(1, s.size() * 2 - 2).find(s);
        // 解释：
        /*
            1. s可由n个子字符串x组成，s=nx;
            2. 2s去除首尾字符，即2s[1, -1];
            3. 则其中含有2(n-1)个x；
            4. 如果x不为s，则n >= 2，即2(n-1) >= 2，故必有一个s；反之则矛盾！
        */
    }
};