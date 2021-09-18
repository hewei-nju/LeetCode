class Solution {
public:
    // 思路：直接想法就是引入map。
    vector<double> sampleStats(vector<int>& count)
    {
        vector<double> res;
        map<int, int> mp;
        for (int i = 0; i < count.size(); ++i) {
            if (count[i] != 0)
                mp.insert({ i, count[i] });
        }
        res.push_back(mp.begin()->first);
        res.push_back(mp.rbegin()->first);
        double avg = 0;
        long cnt = 0;
        for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
            avg += (double)iter->first * iter->second;
            cnt += iter->second;
        }
        res.push_back(avg / cnt);
        int mid = (1 + cnt) / 2;
        if (cnt % 2 == 0) {
            int num = 0;
            for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
                num += iter->second;
                if (num == mid) {
                    res.push_back((iter->first + (++iter)->first) / (double)2);
                    break;
                } else if (num > mid) {
                    res.push_back(iter->first);
                    break;
                }
            }
        } else {
            int num = 0;
            for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
                num += iter->second;
                if (num >= mid) {
                    res.push_back(iter->first);
                    break;
                }
            }
        }
        int num = 0;
        double mulNum = 0;
        for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
            if (iter->second > num) {
                num = iter->second;
                mulNum = iter->first;
            }
        }
        res.push_back(mulNum);
        return res;
    }
};