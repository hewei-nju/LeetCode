class Solution {
public:
    // 思路：emmm，一眼就感觉应该是这样的！所以也不考虑优化了，直接go！
    // 居然超时了！太多的拷贝了！
    // 修改后还是不行，呜呜呜！太晚了，00:57了，sleep!
    int kmp(const string& a, int pos, const string& b)
    {
        if (b.size() > a.size() - pos)
            return -1;
        if (b.size() == 0)
            return -1;
        vector<int> next(b.size(), 0);
        for (int i = 1, j = 0; i < b.size(); ++i) {
            while (j > 0 && b[i] != b[j])
                j = next[j - 1];
            if (b[i] == b[j])
                j += 1;
            next[i] = j;
        }

        for (int i = pos, j = 0; i < a.size();) {
            for (j = 0; j < b.size(); ++j) {
                if (a[i + j] != b[j])
                    break;
            }
            if (j == b.size())
                return i;
            if (j > 0)
                i += j - next[j - 1];
            else
                i += 1;
        }
        return -1;
    }
    // vector<int> findAllIndex(const string& a, const string& b)
    // {
    //     vector<int> res;
    //     string tmp(a);
    //     int pos = 0;
    //     while (!tmp.empty()) {
    //         pos = kmp(tmp, pos + 1, b);
    //         if (pos == -1)
    //             break;
    //         res.push_back(pos);
    //     }
    //     return res;
    // }
    vector<vector<int>> multiSearch(string big, vector<string>& smalls)
    {
        vector<vector<int>> res;
        vector<int> index;
        for (const string& str : smalls) {
            int pos = 0;
            index.clear();
            while (pos != string::npos) {
                pos = kmp(big, pos + 1, str);
                if (pos == -1)
                    break;
                index.push_back(pos);
            }
            res.push_back(index);
        }
        return res;
    }
};

// 改进版（炒的一个题解，其实我觉得我的代码修改后也可以达到这个效果！）
/*
class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        vector<vector<int>> result;
        vector<int> index;
        for (auto& s : smalls) {
            index.clear();
            int pos = big.find(s);
            if (pos == string::npos || s == "") {
                result.push_back(index);
            } else {
                while (pos != string::npos) {
                    index.push_back(pos);
                    pos++;
                    pos = big.find(s, pos);
                }
                result.push_back(index);
            }
        }

        return result;
    }
};

*/