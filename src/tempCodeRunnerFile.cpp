class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int lastWordLength = 0;
        int lastChar = '~';
        int cnt = 0;
        for (int i = 0; i <= len - 1; ++i) {
            if (s[i] == ' ') {
                if (lastChar != ' ') {
                    lastWordLength = cnt;
                }
                cnt = 0;
            } else {
                cnt += 1;
            }
            lastChar = s[i];
        }
        if (cnt != 0) {
            lastWordLength = cnt;
        }
        return lastWordLength;
    }
};
