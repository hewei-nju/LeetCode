
/*给定一个二叉树，返回该二叉树层序遍历的结果，（从左到右，一层一层地遍历）
例如：
给定的二叉树是{3,9,20,#,#,15,7},
该二叉树层序遍历的结果是
[
[3],
[9,20],
[15,7]
]
*/

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
     * @param root TreeNode类 
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > levelOrder(TreeNode* root) {
        // write code here
        vector<vector<int>> res;
        vector<int> tmp;
        queue<TreeNode*> oldQ;
        queue<TreeNode*> newQ;
        if (root != nullptr) 
            oldQ.push(root);
        while (!oldQ.empty() || !newQ.empty()) {
            if (!oldQ.empty()) {
                auto node = oldQ.front();
                cout << node->val << " ";
                oldQ.pop();
                tmp.push_back(node->val);
                if (node->left != nullptr)
                    newQ.push(node->left);
                if (node->right != nullptr)
                    newQ.push(node->right);
            } else {
                res.push_back(tmp);
                tmp.clear();
                oldQ.swap(newQ);
            }
        }
        if (!tmp.empty())
            res.push_back(tmp);
        return res;
    }
};