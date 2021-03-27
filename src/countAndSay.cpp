# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string str;
        string ans;
        for (int i = 1; i <= n; ++i) {
            if (i == 1) {
                ans = "1";
            } else {
                char lastChar = '0';
                int nums = 0;
                int len = ans.length();
                for (int j = 0; j <= len - 1; ++j) {
                    if (ans[j] == lastChar) {
                        nums += 1;
                    } else {
                        if (nums > 0) {
                            str += to_string(nums);
                            str += lastChar;
                        }
                        lastChar = ans[j];
                        nums = 1;
                    }
                }
                if (nums > 0) {
                    str += to_string(nums);
                    str += lastChar;
                }
                ans = str;
                // cout << ans << endl;
                str = "";
            }
        }
        return ans;
    }
};


int main() {
    Solution s;
    cout << s.countAndSay(6) << endl;
}


// 1 -> 1
// 2 -> 1 -> 11
// 3 -> 1 -> 11 -> 21
// 4 -> 1 -> 11 -> 21 -> 1211
// 5 -> 1 -> 11 -> 21 -> 1211 -> 111221 
// 6 -> 1 -> 11 -> 21 -> 1211 -> 111221 -> 312211
// 7 -> 1 -> 11 -> 21 -> 1211 -> 111221 -> 12112221