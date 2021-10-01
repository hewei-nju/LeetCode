class Solution {
public:
    string reverseParentheses(string s) {
        string ret;
        if (s.empty())
            return ret;
        deque<char> deq;
        queue<char> que;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ')') {
                while ((!deq.empty()) && deq.back() != '(') {
                    que.push(deq.back());
                    deq.pop_back();
                }
                deq.pop_back();
                while (!que.empty()) {
                    deq.push_back(que.front());
                    que.pop();
                }
            } else {
                deq.push_back(s[i]);
            }
            ++i;
        }
        while (!deq.empty()) {
            ret += deq.front();
            deq.pop_front();
        }
        return ret;
    }
};