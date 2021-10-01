class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hashMap;
        for (auto &word: words)
            if (hashMap.find(word) != hashMap.end())
                hashMap.at(word) += 1;
            else
                hashMap.insert({word, 1});
        auto cmp = [](pair<string, int> left, pair<string, int> right) {
            if (left.second > right.second)
                return false;
            if (left.second < right.second)
                return true;
            for (int i = 0; i <= left.first.size() - 1; ++i) {
                if (left.first[i] < right.first[i])
                    return false;
                if (left.first[i] > right.first[i])
                    return true;
            }
            return false;
        };
        priority_queue< pair<string, int>, vector<pair<string, int>>, decltype(cmp)>
        pq(cmp);
        for (auto &item: hashMap)
            pq.push(item);
        vector<string> ret;
        while (k > 0) {
            --k;
            ret.push_back(pq.top().first);
            pq.pop();
        }
        return ret;
    }
};