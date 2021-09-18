class Solution {
public:
    // 思路：可以很容易发现，只要计算不同的分数的个数即可。
    int expectNumber(vector<int>& scores)
    {
        set<int> st;
        // set<int> st(scores.begin(), scores.end());  // 这个应该更快些！
        for (auto num : scores)
            st.insert(num);
        return st.size();
    }
};