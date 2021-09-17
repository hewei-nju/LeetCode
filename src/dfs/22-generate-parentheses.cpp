class Solution {
public:
    void dfs(vector<string>& res, int lhs, int rhs, string str) {
        if (lhs == 0 && rhs == 0) {
            res.emplace_back(str);
            return;
        }
        if (lhs > 0)
            dfs(res, lhs - 1, rhs + 1, str + "(");
        if (rhs > 0)
            dfs(res, lhs, rhs - 1, str + ")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        dfs(res, n, 0, s);
        return res;
    }
};