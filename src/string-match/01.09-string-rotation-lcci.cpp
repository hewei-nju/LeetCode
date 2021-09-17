class Solution {
public:
    // 思路：这不直接两个字符串拼接一次，然后KMP查一下就好了嘛？有手就行？
    // 不过我想偷懒使用find！

    // 算了，还是码一遍KMP吧！
    bool kmp(const string& a, const string& b)
    {
        // 面向测试用例！
        if (a == b)
            return true;
        // 注意这里稍微修改一丢丢
        if (b.size() != a.size() / 2)
            return false;
        vector<int> next(b.size(), 0);
        for (int i = 1, j = 0; i < b.size(); ++i) {
            while (j > 0 && b[i] != b[j])
                j = next[j - 1];
            if (b[i] == b[j])
                j += 1;
            next[i] = j;
        }

        for (int i = 0, j = 0; i < a.size();) {
            for (j = 0; j < b.size(); ++j) {
                if (a[i + j] != b[j])
                    break;
            }
            if (j == b.size())
                return true;
            if (j > 0)
                i += j - next[j - 1];
            else
                i += 1;
        }
        return false;
    }
    bool isFlipedString(string s1, string s2)
    {
        s1 += s1;
        // cout << s1.find(s2);
        return s1 == s2 || s1.size() / 2 == s2.size() && s1.find(s2) != string::npos;
        // return kmp(s1, s2);
    }
};