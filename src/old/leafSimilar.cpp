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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1, vec1);
        dfs(root2, vec2);
        for (int i = 0, n1 = vec1.size(), n2 = vec2.size(); n1 == n2 && i < n1; ++i) {
            if (vec1[i] != vec2[i])
                return false;
        }
        return vec1.size() == vec2.size();
    }
    void dfs(TreeNode *root, vector<int> &vec) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
            vec.push_back(root->val);
        dfs(root->left, vec);
        dfs(root->right, vec);
    }
    
private:
    vector<int> vec1;
    vector<int> vec2;
};