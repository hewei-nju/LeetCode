#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>

using namespace std;

int binarySearch(int val, vector<int> &nums)
{ // 假设nums升序
    int len = nums.size();
    int probe = len / 2;
    int diff = static_cast<int>(log2(len));
    while (diff > 0)
    {
        if (probe < len && val > nums[probe])
            probe += diff;
        else if (probe < len && val == nums[probe])
            break;
        else
            probe -= diff;
        diff >>= 1;
    }
    if (probe < len && val == nums[probe])
        return probe;
    else if (probe + 1 < len && val == nums[probe + 1])
        return probe + 1;
    else if (probe - 1 >= 0 && val == nums[probe - 1])
        return probe - 1;
    else
        return -1;
}

int main()
{
    // vector<int> vec;
    // // cout << binarySearch(2, vec) << endl;
    // for (int i = 1; i <= 999999; ++i) {
    //     for (int j = 1; j <= i; ++j) {
    //         vec.push_back(j);
    //     }
    //     int val = 1;
    //     while (val <= vec.size()) {
    //         if (val != binarySearch(val, vec) + 1) {
    //             cout << "false" << endl;
    //             cout << val << " " << i << endl;
    //             return 0;
    //         }
    //         val += 1;
    //     }
    // }
    // // cout << binarySearch(val, vec) << endl;
    // cout << "true" << endl;

    int a[4][20];
    cout << sizeof(a) << endl;
    cout << a << endl;
}