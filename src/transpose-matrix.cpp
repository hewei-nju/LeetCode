# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        for (int j = 0; j <= matrix[0].size() - 1; ++j) {
            for (int i = 0; i <= matrix.size() - 1; ++i) {
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};


int main()
{
    Solution solution;
    // solution.transpose();
}