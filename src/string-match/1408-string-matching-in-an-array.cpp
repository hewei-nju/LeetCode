class Solution {
public:
    // 这题感觉没啥好想法，就直接暴力？
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for (int i = 0, j = 0; i < words.size(); j = 0, ++i) {
            while (j < words.size()) {
                if (words[i].size() < words[j].size() && words[j].find(words[i]) < words[j].npos) {
                    res.push_back(words[i]);
                    break;
                }
                ++j;
            }
        }
        return res;
    }
};