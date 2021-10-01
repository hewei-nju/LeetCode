#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.length() <= 0) {
            return true;
        } else {
            stack<char> opStack;
            for (int i = 0; i <= s.length() - 1; ++i) {
                if (opStack.size() > 0) {
                    if (opStack.top() == '(') {
                        if (s[i] == ')') {
                            opStack.pop();
                        } else {
                            opStack.push(s[i]);
                        }
                    } else if (opStack.top() == '[') {
                        if (s[i] == ']') {
                            opStack.pop();
                        } else {
                            opStack.push(s[i]);
                        }
                    } else if (opStack.top() == '{'){
                        if (s[i] == '}') {
                            opStack.pop();
                        } else {
                            opStack.push(s[i]);
                        }
                    } else {
                        opStack.push(s[i]);
                    }
                } else {
                    opStack.push(s[i]);
                }
            }
            if (opStack.size() > 0) {
                return false;
            } else {
                return true;
            }
        }
    }
};


int main() {
    Solution s;
    cout << s.isValid("([}}])") << endl;
}