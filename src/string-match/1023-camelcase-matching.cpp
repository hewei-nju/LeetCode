class Solution {
public:
    bool fit(const string& a, const string &b) {
        for (int i = 0, j = 0; i < b.size();) {
            while (j < a.size()) {
                if (b[i] == a[j])
                    i += 1;
                else if (isupper(a[j]))
                    return false;
                j += 1;
            }
            if (j == a.size() && i < b.size())
                return false;
        }
        return true;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            res[i] = fit(queries[i], pattern);
        }
        return res;
    }
};