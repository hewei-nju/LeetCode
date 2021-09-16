// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

class Solution {
public:
    // 思路：因为s的移动其最多s.size()次，因此，可以直接用s.size()个s叠加，然后查找是否有goal子字符串；这就转换为了kmp算法；
    // 思路2：直接朴素算法，从a中找，找到第一个字符匹配，然后进行下一次，然后循环匹配即可，看是否能找到所有的。。。
    bool useKMP(const string& a, const string& b)
    {
        if (a.size() != b.size())
            return false;
        int cnt = a.size();
        string t(a);
        while (--cnt > 0)
            t += a;

        vector<int> next(b.size(), 0);
        int i, j;
        for (int i = 1, j = 0; i < b.size(); ++i) {
            while (j > 0 && b[i] != b[j])
                j = next[j - 1];
            if (b[i] == b[j])
                j += 1;
            next[i] = j;
        }
        for (i = 0; i < t.size();) {
            for (j = 0; j < b.size(); ++j) {
                if (t[i + j] != b[j]) {
                    break;
                }
            }
            if (j == b.size())
                return true;
            i += (j > 0 ? j - next[j - 1] : 1);
        }
        return false;
    }

    bool simpleThough(const string& a, const string& b)
    {
        if (a.size() != b.size())
            return false;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[0]) {
                int j;
                for (j = 0; j < b.size(); ++j) {
                    if (a[(i + j) % a.size()] != b[j]) {
                        break;
                    }
                }
                if (j == b.size())
                    return true;
            }
        }
        return false;
    }
    bool rotateString(string s, string goal)
    {
        // return useKMP(s, goal);
        return simpleThough(s, goal);
    }
};

// int main()
// {
//     Solution s;
//     cout << std::boolalpha << s.rotateString("aabbaa", "baaaab");
// }  ![image.png](https://pic.leetcode-cn.com/1631785721-jgxEQo-image.png)