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
    bool isSame(TreeNode* lhs, TreeNode* rhs) {
        if (lhs == nullptr && rhs == nullptr)
            return true;
        if (lhs == nullptr || rhs == nullptr)
            return false;
        if (lhs->val == rhs->val)
            return isSame(lhs->left, rhs->left) && isSame(lhs->right, rhs->right);
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr)
            return true;
        if (root == nullptr)
            return false;
        if (root->val == subRoot->val) {
            bool res = isSame(root, subRoot);
            if (res)
                return res;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};