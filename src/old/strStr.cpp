class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }
        int pos = -1;
        bool head = true;
        int i = 0, j = 0;
        int len = haystack.length();
        for (; i <= len - 1; ++i) {
            if (haystack[i] == needle[j]) {
                if (head) {
                    pos = i;
                }
                ++j;
                head = false;
            } else if (haystack[i] != needle[j]){
                if (!head) {
                    i = pos;
                }
                pos = -1;
                j = 0;
                head = true;
            }
            if (j == needle.length()) {
                break;
            }
        }
        if (j == needle.length()) {
            return pos;
        } else {
            return -1;
        }
    }
};