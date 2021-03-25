#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() <= 0) {
            return "";
        }
        string base_str = strs[0];
        // cout << base_str << endl;
        for (string str : strs) {
            if (base_str == "") {
                return base_str;
            }
            int i = 0;
            string tmp_str = "";
            while (i <= base_str.length() - 1 && i <= str.length() - 1) {
                if (base_str[i] != str[i]) {
                    base_str = tmp_str;
                    // cout << base_str << endl;
                    // cout << tmp_str << endl;
                    break;
                }
                tmp_str += str[i];
                ++i;
            }
            if (i == base_str.length() || i == str.length()) {
                base_str = tmp_str;
            }
        }
        return base_str;
    }
};


// int main() {
//     Solution solution;
//     vector<string> strs{"dog","racecar","car"};
//     cout << solution.longestCommonPrefix(strs) << endl;
// }
