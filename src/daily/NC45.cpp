// 实现二叉树的先、中、后序遍历

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    void preOrder(TreeNode* root, vector<int>& ret)
    {
        if (root != nullptr) {
            ret.push_back(root->val);
            preOrder(root->left, ret);
            preOrder(root->right, ret);
        }
    }
    void inOrder(TreeNode* root, vector<int>& ret)
    {
        if (root != nullptr) {
            inOrder(root->left, ret);
            ret.push_back(root->val);
            inOrder(root->right, ret);
        }
    }
    void postOrder(TreeNode* root, vector<int>& ret)
    {
        if (root != nullptr) {
            postOrder(root->left, ret);
            postOrder(root->right, ret);
            ret.push_back(root->val);
        }
    }
    vector<vector<int>> threeOrders(TreeNode* root)
    {
        // write code here
        vector<int> prev;
        vector<int> in;
        vector<int> post;
        preOrder(root, prev);
        inOrder(root, in);
        postOrder(root, post);
        vector<vector<int>> res { prev, in, post };
        return res;
    }
};