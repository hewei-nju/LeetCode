#include <iostream>
using namespace std;
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
		assert(nums.size() >= 1);
		int ret = 0;
		for (int i = 0; i < 32; ++i) {
			int cnt = 0;
			for (auto &num: nums) {
				if ((num & 1) == 1)
					cnt += 1;
				num >>= 1;
			}
			ret += cnt * (nums.size() - cnt);
		}
			return ret;
	}

};