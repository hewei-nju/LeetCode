#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                int cnt = 1;
                left = mid - 1, right = mid + 1;
                while (left >= 0 && right <= nums.size() - 1 &&(nums[left] == target || nums[right] == target))
                {
                    if (nums[left] == target) {
                        cnt += 1;
                    }
                    if (nums[right] == target) {
                        cnt += 1;
                    }
                    left -= 1;
                    right += 1;
                }
                while (left >= 0 && nums[left] == target) {
                    cnt += 1;
                    left -= 1;
                }
                while (right <= nums.size() - 1 && nums[right] == target) {
                    cnt += 1;
                    right += 1;
                }
                return cnt;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return 0;
    }
};





int main()
{
    vector<int> vec{5, 7, 7, 8, 8, 10};
    Solution s;
    cout << s.search(vec, 8) << endl;
}