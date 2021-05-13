class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, sell = 0, lock = 0;
        for (auto &p: prices) {
            buy = max(buy, lock - p);
            lock = sell;
            sell = max(sell, buy + p);
        }
        return sell;
    }
};