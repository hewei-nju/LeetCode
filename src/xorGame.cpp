class Solution {
public:
    bool xorGame(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        int ret = 0;
        int zeros = 0;
        for (auto num: nums) {
            ret ^=  num;
            if (num == 0) {
                zeros += 1;
                continue;
            }
            if (hashMap.find(num) != hashMap.end()) {
                hashMap.at(num) += 1;
            } else {
                hashMap.insert({num, 1});
            }
        }
        if (ret == 0)
            return true;
        else
            ret = 0;
        for (auto item: hashMap) {
            ret += item.second & 1;
        }
        if ((zeros & 1) == 0)
            return (ret & 1) == 0;
        else 
            return (ret & 1) != 0;
    }
};