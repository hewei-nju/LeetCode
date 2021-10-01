#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length() - 1;
        int len2 = b.length() - 1;
        string ans;
        char carry = '0';
        while (len1 >= 0 && len2 >= 0) {
            if (carry == '0') {
                if (a[len1] == '1' && b[len2] == '1') {
                    ans += '0';
                    carry = '1';
                } else if (a[len1] == '0' && b[len2] == '0') {
                    ans += '0';
                    carry = '0';
                } else {
                    ans += '1';
                    carry = '0';
                }
            } else {
                if (a[len1] == '1' && b[len2] == '1') {
                    ans += '1';
                    carry = '1';
                } else if (a[len1] == '0' && b[len2] == '0') {
                    ans += '1';
                    carry = '0';
                } else {
                    ans += '0';
                    carry = '1';
                }
            }
            len1 -= 1;
            len2 -= 1;
        }
        while (len1 >= 0) {
            if (carry == '0') {
                ans += a[len1];
            } else {
                if (a[len1] == '1') {
                    ans += '0';
                    carry = '1';
                } else {
                    ans += '1';
                    carry = '0';
                }
            }
            len1 -= 1;
        }
        while (len2 >= 0) {
            if (carry == '0') {
                ans += b[len2];
            } else {
                if (b[len2] == '1') {
                    ans += '0';
                    carry = '1';
                } else {
                    ans += '1';
                    carry = '0';
                }
            }
            len2 -= 1;
        }
        if (carry == '1') {
            ans += carry;
        }
        int len = ans.length();
        cout << ans << endl;
        for (int i = 0; i <= (len - 1) / 2; ++i) {
            char ch = ans[i];
            ans[i] = ans[len - i - 1];
            ans[len - i - 1] = ch;
        }
        return ans;
    }
};


int main() {
    Solution s;
    cout << s.addBinary("1010", "1011") << endl;
}