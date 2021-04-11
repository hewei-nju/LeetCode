class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> Aset;
        for (auto num: nums) {
            auto search = Aset.find(num);
            if (search != Aset.end()) {
                return true;
            }
            Aset.insert(num);
        }
        return false;
    }
};