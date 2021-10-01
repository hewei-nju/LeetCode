#include <iostream>
#include <vector>

using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        int head = 0, tail = nums.size() - 1, mid = head + ((tail - head) >> 1);
        TreeNode *root = new TreeNode;
        root->val = nums[mid];
        sortedArrayToBST(root, nums, head, mid - 1, mid + 1, tail);
        return root;
    }

    void sortedArrayToBST(TreeNode *root, vector<int>& nums, int leftHead, int leftTail, int rightHead, int rightTail) {
        if (leftHead >= 0 && leftTail >= 0 && leftHead <= leftTail) {
            int leftMid = leftHead + ((leftTail - leftHead) >> 1);
            TreeNode *left = new TreeNode;
            left->left = nullptr;
            left->right = nullptr;
            left->val = nums[leftMid];
            root->left = left;
            sortedArrayToBST(root->left, nums, leftHead, leftMid - 1, leftMid + 1, leftTail);
        }
        if (rightHead >= 0 && rightTail >= 0 && rightHead <= rightTail) {
            int rightMid = rightHead + ((rightTail - rightHead) >> 1);
            TreeNode *right = new TreeNode;
            right->left = nullptr;
            right->right = nullptr;
            right->val = nums[rightMid];
            root->right = right;
            sortedArrayToBST(root->right, nums, rightHead, rightMid - 1, rightMid + 1, rightTail);
        }

    }
};

void print(TreeNode *root)
{
    if (root == nullptr) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}

int main()
{
    vector<int> nums {-10, -3, 0, 5, 9};
    Solution s;
    TreeNode *root = s.sortedArrayToBST(nums);
    print(root);
}