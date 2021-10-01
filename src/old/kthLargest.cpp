#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto &x: nums)
            add(x);
    }

    int add(int val) {
        this->pq.push(val);
        if (this->pq.size() > k) {
            this->pq.pop();
        }
        return this->pq.top();
    }


private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main()
{
    vector<int> vec{4, 5, 8, 2};
    KthLargest kth(3, vec);
    cout << kth.add(3) << endl;
    cout << kth.add(1) << endl;
}