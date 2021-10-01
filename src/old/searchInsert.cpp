# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int head = 0, tail = nums.size();
        int mid = head +(tail - head) / 2;
        while (head < tail) {
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                head = mid + 1;
                if (head == nums.size() || target < nums[head]) {
                    return head;
                }
            } else {
                tail = mid - 1;
                if (tail < 0 || target > nums[tail]) {
                    return mid;
                }
            }
            mid = (head + tail) / 2;
        }
        return head;
    }
};


int main() {
    Solution s;
    vector<int> nums{1, 3, 5, 6};
    cout << s.searchInsert(nums, 0) << endl;
}