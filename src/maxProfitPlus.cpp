class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxProfit = 0;
        int curLowPrice = prices[0];
        int curHighPrice = prices[0];
        int len = prices.size() - 1;
        for (int i = 1; i <= len; ++i) {
            if (prices[i] < curHighPrice) {
                maxProfit += curHighPrice - curLowPrice;
                curLowPrice = prices[i];
                curHighPrice = prices[i];
            } else {
                curHighPrice = prices[i];
            }
        }
        return maxProfit + curHighPrice - curLowPrice;
    }
};