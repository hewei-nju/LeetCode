#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// class Solution1    // 错误算法
// {
// public:
//     int maxProfit(vector<int> &prices){
//         if (prices.size() == 0)
//             return 0;
//         int min1 = 100001, max1 = 0, min2 = 100001, max2 = 0;
//         int minT = 100001, maxT = 0;
//         /**
//          * min1 max1 min2 max2 minT maxT
//          * min1 < max1, max1 > min2, min2 < max2, max2 > minT, minT < maxT
//          * max has five choices bellow:
//          * min1 max1 min2 max2
//          * min1 max1 min2 maxT
//          * min1 max1 minT maxT
//          * min1 max2 minT maxT
//          * min2 max2 minT maxT
//         */
//         minT = prices[0];
//         for (int i = 1, len = prices.size(); i < len; ++i){
//             if (prices[i] < minT) {
//                 if (maxT != 0) {
//                     if (min1 == 100001){
//                         min1 = minT;
//                         max1 = maxT;
//                     } else if (min2 == 100001) {
//                         min2 = minT;
//                         max2 = maxT;
//                     }else{
//                         int sum1 = max1 - min1 + max2 - min2;
//                         int sum2 = max1 - min1 + maxT - min2;
//                         int sum3 = max1 - min1 + maxT - minT;
//                         int sum4 = max2 - min1 + maxT - minT;
//                         int sum5 = max2 - min2 + maxT - minT;
//                         int res = max(sum1, sum2);
//                         res = max(res, sum3);
//                         res = max(res, sum4);
//                         res = max(res, sum5);
//                         if (res == sum1)
//                         {
//                         }
//                         else if (res == sum2)
//                         {
//                             max2 = maxT;
//                         }
//                         else if (res == sum3)
//                         {
//                             min2 = minT;
//                             max2 = maxT;
//                         }
//                         else if (res == sum4)
//                         {
//                             max1 = max2;
//                             min2 = minT;
//                             max2 = maxT;
//                         }
//                         else if (res == sum5)
//                         {
//                             min1 = min2;
//                             max1 = max2;
//                             min2 = minT;
//                             max2 = maxT;
//                         }
//                     }
//                 }
//                 minT = prices[i];
//                 maxT = 0;
//             }
//             else {
//                 if (prices[i] >= maxT)
//                 {
//                     maxT = prices[i];
//                 }
//                 else
//                 {
//                     if (maxT != 0)
//                     {
//                         if (min1 == 100001)
//                         {
//                             min1 = minT;
//                             max1 = maxT;
//                         }
//                         else if (min2 == 100001)
//                         {
//                             min2 = minT;
//                             max2 = maxT;
//                         }
//                         else
//                         {
//                             int sum1 = max1 - min1 + max2 - min2;
//                             int sum2 = max1 - min1 + maxT - min2;
//                             int sum3 = max1 - min1 + maxT - minT;
//                             int sum4 = max2 - min1 + maxT - minT;
//                             int sum5 = max2 - min2 + maxT - minT;
//                             int res = max(sum1, sum2);
//                             res = max(res, sum3);
//                             res = max(res, sum4);
//                             res = max(res, sum5);
//                             if (res == sum1)
//                             {
//                             }
//                             else if (res == sum2)
//                             {
//                                 max2 = maxT;
//                             }
//                             else if (res == sum3)
//                             {
//                                 min2 = minT;
//                                 max2 = maxT;
//                             }
//                             else if (res == sum4)
//                             {
//                                 max1 = max2;
//                                 min2 = minT;
//                                 max2 = maxT;
//                             }
//                             else if (res == sum5)
//                             {
//                                 min1 = min2;
//                                 max1 = max2;
//                                 min2 = minT;
//                                 max2 = maxT;
//                             }
//                         }
//                     }
//                     minT = prices[i];
//                     maxT = 0;
//                 }
//             }
//         }
//         if (maxT != 0)
//         {
//             if (min1 == 100001)
//             {
//                 min1 = minT;
//                 max1 = maxT;
//             }
//             else if (min2 == 100001)
//             {
//                 min2 = minT;
//                 max2 = maxT;
//             }
//             else
//             {
//                 int sum1 = max1 - min1 + max2 - min2;
//                 int sum2 = max1 - min1 + maxT - min2;
//                 int sum3 = max1 - min1 + maxT - minT;
//                 int sum4 = max2 - min1 + maxT - minT;
//                 int sum5 = max2 - min2 + maxT - minT;
//                 int res = max(sum1, sum2);
//                 res = max(res, sum3);
//                 res = max(res, sum4);
//                 res = max(res, sum5);
//                 if (res == sum1)
//                 {
//                 }
//                 else if (res == sum2)
//                 {
//                     max2 = maxT;
//                 }
//                 else if (res == sum3)
//                 {
//                     min2 = minT;
//                     max2 = maxT;
//                 }
//                 else if (res == sum4)
//                 {
//                     max1 = max2;
//                     min2 = minT;
//                     max2 = maxT;
//                 }
//                 else if (res == sum5)
//                 {
//                     min1 = min2;
//                     max1 = max2;
//                     min2 = minT;
//                     max2 = maxT;
//                 }
//             }
//         }
//         int ret = 0;
//         if (max1 - min1 > 0)
//             ret += max1 - min1;
//         if (max2 - min2 > 0)
//             ret += max2 - min2;
//         return ret;
//     }
// };
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int fstBuy = -prices[0], fstSell = 0;
        int secBuy = -prices[0], secSell = 0;
        for (auto &price: prices)
        {
            fstBuy = max(fstBuy, -price);
            fstSell = max(fstSell, fstBuy + price);
            secBuy = max(secBuy, fstSell - price);
            secSell = max(secSell, secBuy + price);
        }
        return secSell;
    }
};

int main()
{
    // vector<int> prices{3, 3, 5, 0, 0, 1, 4};
    vector<int> prices1{18, 9305, 107, 9957, 1, 4303, 131, 9996, 2, 9214, 1007, 9972};

    Solution s;
    // Solution1 s1;
    vector<int> vec{118, 9957, 1, 2245, 131, 9996, 2, 9970};
    cout << s.maxProfit(prices1) << endl;
    // cout << s1.maxProfit(prices1) << endl;
}