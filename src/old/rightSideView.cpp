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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> que;
        vector<int> ret;
        if (root == nullptr)
            return ret;
        que.push(root);
        TreeNode *TAG = root;
        while (!que.empty()) {
            TreeNode *front = que.front();
            que.pop();
            if (front->right)
                que.push(front->right);
            if (front->left)
                que.push(front->left);
            if (front == TAG || front == TAG->right || front == TAG->left) {
                ret.push_back(front->val);
                TAG = front;
            }
            if (TAG->left == nullptr && TAG->right == nullptr)
                TAG = front;
        }
        return ret;
    }
};