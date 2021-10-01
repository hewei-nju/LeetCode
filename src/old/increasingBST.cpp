/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *last;
    TreeNode* increasingBST(TreeNode *root) {
        TreeNode *ret = new TreeNode(-1);
        last = ret;
        inOrder(root);
        return ret->right;
    }
    void inOrder(TreeNode* cur) {
        if (cur == nullptr) {
            return;
        }
        inOrder(cur->left);
        last->right = cur;
        cur->left = nullptr;
        last = cur;
        inOrder(cur->right);
    }
};