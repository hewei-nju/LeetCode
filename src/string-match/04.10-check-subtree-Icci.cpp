/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 思路：cao！这题感觉突然让我想起看过一句话：树的前序遍历，然后其顺序同子树在其间的顺序一致！
    // 换句话说：如果某一棵树的前序遍历在另一个树的前序遍历中出现过，并且是顺序出现，则必为其子树。
    // 就转换成了KMP算法了！淦！
    // 既然都碰到了，那就简单思考下吧：
    /* 
    其实我就瞎想了一下，然后维基百科搜了下树得遍历，个人觉得，只要把所有的位置都给表示出来，其实每种遍历都能把完整的树的结构信息保存下来的！

    因为你都是通过同一种方式去遍历，并且每次访问的位置都相同，如果存在子结构，那必然存在同一块子序列是相同的！


    !!!:经过简单验证确实如此！不过线序遍历好写一些。
    */
    // 另一种想法：朴素的暴力搜索啦！直接递归即可，代码好写很多很多！这中写法其实应该是在另一个题中写过了，确实很简单，就不写了。

    void pre(TreeNode* root, vector<long>& nums)
    {
        if (root == nullptr) {
            nums.push_back(LONG_MAX);
            return;
        }
        nums.push_back(root->val);
        pre(root->left, nums);
        pre(root->right, nums);
    }
    void in(TreeNode* root, vector<long>& nums)
    {
        if (root != nullptr)
            in(root->left, nums);
        if (root == nullptr) {
            nums.push_back(LONG_MAX);
            return;
        }
        nums.push_back(root->val);
        if (root != nullptr)
            in(root->right, nums);
    }
    void post(TreeNode* root, vector<long>& nums)
    {
        if (root != nullptr)
            post(root->left, nums);
        if (root != nullptr)
            post(root->right, nums);
        if (root == nullptr) {
            nums.push_back(LONG_MAX);
            return;
        }
        nums.push_back(root->val);
    }

    bool kmp(const vector<long>& a, const vector<long>& b)
    {
        if (b.size() > a.size())
            return false;
        vector<int> next(b.size(), 0);
        for (int i = 1, j = 0; i < b.size(); ++i) {
            while (j > 0 && b[i] != b[j])
                j = next[j - 1];
            if (b[i] == b[j])
                j += 1;
            next[i] = j;
        }
        for (int i = 0, j = 0; i < a.size();) {
            for (j = 0; j < b.size(); ++j) {
                if (a[i + j] != b[j])
                    break;
            }
            if (j == b.size())
                return true;
            if (j > 0)
                i += j - next[j - 1];
            else
                i += 1;
        }
        return false;
    }
    bool checkSubTree(TreeNode* t1, TreeNode* t2)
    {
        vector<long> a;
        vector<long> b;

        // pre(t1, a);
        // pre(t2, b);

        // in(t1, a);
        // in(t2, b);

        post(t1, a);
        post(t2, b);
        return kmp(a, b);
    }
};