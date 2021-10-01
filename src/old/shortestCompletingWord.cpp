class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> keyMap(26, 0);
        for (auto s: licensePlate)
            if (isalpha(s))
                keyMap[tolower(s) - 97] += 1;
        string ret;
        for (auto &word: words) {
            vector<int> vec_t(26, 0);
            for (auto s: word)
                if (isalpha(s))
                    vec_t[tolower(s) - 97] += 1;
            if (satisfy(keyMap, vec_t))
                if (word.size() < ret.size() || ret.empty())
                    ret = word;
        }
        return ret;
        }

    bool satisfy(const vector<int> &dest, const vector<int> &src) {
        for (int i = 0, len = dest.size(); i < len; ++i) {
            if (dest[i] > src[i])
                return false;
        }
        return true;
    }

};