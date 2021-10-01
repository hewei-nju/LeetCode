class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int lastBuy = INT_MIN, lastSell = 0;
        int nextBuy = INT_MIN, nextSell = 0;
        for (auto &price: prices) {
            nextBuy = max(nextBuy, lastSell - price - fee);
            nextSell = max(nextBuy + price, nextSell);
            lastBuy = nextBuy;
            lastSell = nextSell;
        }
        return lastSell;
    }
};