class Solution {
public:
    int clumsy(int N) {
        int ret = 0;
        bool first = true;
        for (; N >= 1;) {
            int tmp = 0;
            for (int j = 0; j <= 2 && N >= 1; ++j, --N) {
                if (j == 0) {
                    tmp = N;
                } else if (j % 3 == 1) {
                    tmp *= N;
                } else if (j % 3 == 2) {
                    tmp /= N;
                }
            }
            if (N >= 1) {
                ret += N;
            }
            N -= 1;
            if (first) {
                ret += tmp;
                first = false;
            } else {
                ret -= tmp;
            }
        }
        return ret;
    }
};


#include <iostream>
using namespace std;

int main()
{
    Solution s;
    cout << s.clumsy(10) << endl;
}