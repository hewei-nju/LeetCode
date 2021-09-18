#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // 思路：先找到从头开始的最长回文串，然后把末尾的直接逆序贴过来。
    // 淦！超时了！
    // 考虑出现了前缀问题，看kmp能不能用上去？
    // s1 是 s的最大回文串前缀，s'是逆序，则s1'是s1的逆序，则s1' = s1，是s'的后缀
    // 现在问题转换为求s1 + s'的最大相同前后缀，即kmp的next数组
    bool isPalindrome(const string& s, int pos)
    {
        for (int i = 0; i < pos; ++i, --pos) {
            if (s[i] != s[pos])
                return false;
        }
        return true;
    }

    // string shortestPalindrome(string s)
    // {
    //     int i;
    //     for (i = s.size() - 1; i > 0; --i) {
    //         if (isPalindrome(s, i))
    //             break;
    //     }
    //     if (i == s.size() - 1)
    //         return s;
    //     string t = s.substr(i + 1);
    //     reverse(t.begin(), t.end());
    //     return t + s;
    // }

    // 求不大于s长度一半的前后缀
    // a a c e c a a a | a a a c e c a a
    void getNext(const string& s, vector<int>& next)
    {
        for (int i = 1, j = 0; i < s.size(); ++i) {
            while (j > 0 && (s[i] != s[j] || (j + 1) * 2 > s.size()))
                j = next[j - 1];
            if (s[i] == s[j])
                j += 1;
            next[i] = j;
        }
    }

    string shortestPalindrome(string s)
    {
        if (s.empty())
            return s;
        string t(s.rbegin(), s.rend());
        s += t;
        vector<int> next(s.size(), 0);
        getNext(s, next);
        return t.substr(0, s.size() / 2 - next[s.size() - 1]) + s.substr(0, s.size() / 2);
    }
};


int main()
{
    Solution s;
    s.shortestPalindrome("aacecdaaa");
}

// a b c
// a c d
// 1 0 0