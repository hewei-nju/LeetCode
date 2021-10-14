class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // O(n)
        return max_element(arr.begin(), arr.end()) - arr.begin();
    }
};