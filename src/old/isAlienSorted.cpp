class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.size(); ++i)
            this->charMap.insert({order[i], i});
        if (words.size() <= 1)
            return true;
        for (int i = 0; i < words.size() - 1; ++i) {
            if (!dictCompare(words[i], words[i + 1]))
                return false;
        }
        return true;
    }

    bool dictCompare(string s1, string s2) 
    {
        int i = 0, j = 0;
        while (i < s1.size() && j < s2.size()) {
            if (charMap.at(s1[i]) < charMap.at(s2[j]))
                return true;
            else if (charMap.at(s1[i]) > charMap.at(s2[j]))
                return false;
            ++i, ++j;
        }
        return s1.size() <= s2.size();
    }

private:
    unordered_map<char, int> charMap;
};