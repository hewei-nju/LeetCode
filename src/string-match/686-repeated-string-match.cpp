class Solution {
public:
    /* 思路：
    1. 从a中找到第一个与b首字符匹配的字符，然后向下去进行循环匹配，直到不匹配；
    2. 然后从该第一个字符向后继续寻找，重复上述过程，直到到达a字符串的结尾
    */
    // 算法二：其实可以转换来使用KMP
    int repeatedStringMatch(string a, string b)
    {
        assert(a.size() > 0 && b.size() > 0);
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[0]) {
                int j, res = 1;
                for (j = 0; j < b.size(); ++j) {
                    if (a[(i + j) % a.size()] != b[j])
                        break;
                    if ((i + j) % a.size() == a.size() - 1 && j != b.size() - 1)
                        res += 1;
                }
                if (j == b.size())
                    return res;
            }
        }
        return -1;
    }
};