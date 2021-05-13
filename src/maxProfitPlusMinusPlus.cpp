class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, sell = 0, freeze = 0;
        for (auto &p: prices) {
            buy = max(buy, freeze - p);
            freeze = sell;  // 注意freeze和sell的顺序！
            sell = max(sell, buy + p);
        }
        return sell;  
    }
    /**
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, sell = 0, lock = 0;
        for (auto &p: prices) {
            buy = max(buy, lock - p);
            lock = sell;
            sell = max(sell, buy + p);
        }
        return sell;
    }
    */

};