class Solution
{
public:
    /*** time out!  O(nm)
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ret;
        int len = arr.size();
        if (len == 0)
            return ret;
        for (auto item: queries) {
            int left = item[0], right = item[1];
            int ans = 0;
            while (left <= right) 
                ans ^= arr[left++];
            ret.push_back(ans);
        }
        return ret;
    }
    */
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
        vector<int> ret;
        if (arr.size() == 0)
            return ret;
        vector<int> XOR;
        XOR.push_back(0);
        for (int i = 1; i <= arr.size(); ++i) {
            XOR.push_back(XOR[i - 1] ^ arr[i - 1]);
        }
        for (auto vec: queries) {
            ret.push_back(XOR[vec[0]] ^ XOR[vec[1] + 1]);
        }
        return ret;
    }
};