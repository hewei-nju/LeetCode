#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // 思路：第一个想到的朴素思想，但是感觉太慢了！
    // 然后稍微想一下，感觉使用KMP + 二分思想是否可以呢？大概率可以！
    bool isSubString(const string& a, const std::string& b)
    {
        if (b.size() > a.size())
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

    int maxRepeating(string sequence, string word)
    {
        int len = sequence.size() / word.size();
        if (len == 0)
            return 0;
        string words;
        // 突然发现没有string(int, const string&)这个构造函数，也就是说我这种方法开销更大！裂开！
        // 但是思想我觉得还行吧！
        for (int i = 0; i < len; ++i)
            words += word;

        int left = 0, right = len + 1;
        int res;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isSubString(sequence, words.substr(0, mid * word.size()))) {
                left = mid + 1;
                res = mid;
            } else {
                right = mid;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    s.maxRepeating("ababc", "ba");
}