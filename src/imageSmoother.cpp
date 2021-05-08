#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ret;
        int row = img.size();
        int col = 0;
        if (row > 0) {
            col = img[0].size();
        }
        for (int i = 0; i <= row - 1; ++i) {
            vector<int> vec;
            for (int j = 0; j <= col - 1; ++j) {
                int cnt = 0;
                int sum = 0;
                if (i - 1 >= 0 && j - 1 >= 0) {
                    cnt += 1;
                    sum += img[i - 1][j - 1];
                } 
                if (i - 1 >= 0) {
                    cnt += 1;
                    sum += img[i - 1][j];
                }
                if (i - 1 >= 0 && j + 1 <= col - 1) {
                    cnt += 1;
                    sum += img[i - 1][j + 1];
                }
                if (j - 1 >= 0) {
                    cnt += 1;
                    sum += img[i][j - 1];
                }
                cnt += 1;
                sum += img[i][j];
                if (j + 1 <= col - 1) {
                    cnt += 1;
                    sum += img[i][j + 1];
                }
                if (i + 1 <= row - 1 && j - 1 >= 0) {
                    cnt += 1;
                    sum += img[i + 1][j - 1];
                }
                if (i + 1 <= row - 1) {
                    cnt += 1;
                    sum += img[i + 1][j];
                }
                if (i + 1 <= row - 1 && j + 1 <= col - 1) {
                    cnt += 1;
                    sum += img[i + 1][j + 1];
                }
                vec.push_back(sum / cnt);
            }
            ret.push_back(vec);
        }
        return ret;
    }
};


int main()
{
    Solution s;
    vector<vector<int>> img{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    auto res = s.imageSmoother(img);
    for (int i = 0; i <= img.size() - 1; ++i) {
        for (int j = 0; j <= img.size() - 1; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}