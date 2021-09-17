#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // 思路：直接双指针吧！一眼就它了
    int isPrefixOfWord(string sentence, string searchWord)
    {
        int res = 1;
        for (int i = 0, j = 0; i < sentence.size(); ++i) {
            if (sentence[i] == ' ') {
                res += 1;
                continue;
            }
            if ((i == 0 || isspace(sentence[i - 1])) && sentence[i] == searchWord[0]) {
                for (j = 0; j < searchWord.size(); ++i, ++j) {
                    if (isspace(sentence[i]) || sentence[i] != searchWord[j])
                        break;
                }
                // 注意这两个if的顺序，简单思考下
                if (j == searchWord.size())
                    return res;
                if (isspace(sentence[i]))
                    res += 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    s.isPrefixOfWord("b bu bur burg burger", "burg");
}