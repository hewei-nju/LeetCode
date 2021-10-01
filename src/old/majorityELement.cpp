#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int count = 1;
        for (int i = 1; i <= nums.size() - 1; i++) {
            if (count == 0) {
                //前面都消完了，在重新赋值
                count++;
                major = nums[i];
            } else if (major == nums[i]) {
                //自己人，count就加1
                count++;
            } else {
                //不是自己人就同归于尽，消掉一个
                count--;
            }
        }
        return major;
    }
};


int main()
{
    vector<int> nums{6, 5, 5};
    Solution s;
    cout << s.majorityElement(nums) << endl;
}