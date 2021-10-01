#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>
using namespace std;

#define max(num1, num2) (num1 > num2 ? num1 : num2);

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        map<string, int> amap;
        int len = points.size();
        int ret = 0;
        for (int i = 0; i < len; ++i) {
            int maxInline = 1;
            int maxNumHorizen = 1;
            int maxNumVertical = 1;
            for (int j = i + 1; j < len; ++j) {
                string k = slot(points[i][0], points[i][1], points[j][0], points[j][1]);
                // cout << k << endl;
                if (k == "0 1")
                    maxNumHorizen += 1;
                if (k == "1 0")
                    maxNumVertical += 1;
                else {
                    auto search = amap.find(k);
                    if (search != amap.end())
                        search->second += 1;
                    else
                        amap.insert({k, 1});
                    maxInline = max(maxInline, amap.at(k));
                }
            }
            ret = max(ret, maxInline);
            ret = max(ret, maxNumHorizen);
            ret = max(ret, maxNumVertical);
            amap.clear();
        }
        return ret;
    }

    int GCD(int a, int b) {
        int leftShift = 0;
        while ((a & 1) == 0 && (b & 1) == 0) {
            leftShift += 1;
            a >>= 1;
            b >>= 1;
        }
        while ((a & 1) == 0) a >>= 1;
        while ((b & 1) == 0) b >>= 1;
        if (a < b) swap(a, b);
        while ((a = ((a-b) >> 1)) != 0) {
            while ((a & 1) == 0) a >>= 1;
            if (a < b) swap(a, b);
        }
        return b << leftShift;     
    }

    string slot(int x1, int y1, int x2, int y2) {
        int delta_x = x1 - x2;
        int delta_y = y1 - y2;
        if (delta_x == 0 && delta_y == 0)
            return "0 0";
        else if (delta_x == 0)
            return "0 1";
        else if (delta_y == 0)
            return "1 0";
        else if (delta_x > 0 && delta_y > 0 || delta_x < 0 && delta_y < 0) {
            delta_x = abs(delta_x);
            delta_y = abs(delta_y);
            return to_string(delta_x / GCD(delta_x, delta_y)) + " " + to_string(delta_y / GCD(delta_x, delta_y));
        } else {
            delta_x = abs(delta_x);
            delta_y = abs(delta_y);
            return "-" + to_string(delta_x / GCD(delta_x, delta_y)) + " " + to_string(delta_y / GCD(delta_x, delta_y));
        }
    }
};


int main()
{
    Solution s;
    vector<vector<int>> points{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    cout << s.maxPoints(points);
}