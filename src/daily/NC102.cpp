/*
给定一棵二叉树(保证非空)以及这棵树上的两个节点对应的val值 o1 和 o2，请找到 o1 和 o2 的最近公共祖先节点。

数据范围：1≤n≤1000，树上每个节点的val满足 0<<val≤100
要求：空间复杂度 O(1)，时间复杂度 O(n)

注：本题保证二叉树中每个节点的val值均不相同。

如当输入[3,5,1,6,2,0,8,#,#,7,4],5,1时，返回3
*/

// 思路：关于二叉树，大多可以往递归方向思考
// root == null ===> return -1
// root->val == o1 | root->val == o2 ===> return root->val
// 对左子树递归，如果没有查找到，则返回值为-1，否则查找到至少一个
// 对右子树递归，如果没有查找到，则返回值为-1，否则查找到至少一个
// 然后根据查找到几个来判断返回值

// 1. 如果root的值为o1或o2，显然root即为最近公共祖先
// 2. 如果o1, o2分别在左子树和右子树，那么显然root为最近公共祖先
// 3. 如果o1, o2在左子树，则递归上面的1，2步骤，否则返回-1
// 4. 如果o1, o2在右子树，则同理。
// 然后根据查找到几个来判断返回值


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
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2)
    {
        // write code here
        if (root == nullptr)
            return -1;
        if (root->val == o1 || root->val == o2)
            return root->val;
        int left = lowestCommonAncestor(root->left, o1, o2);
        int right = lowestCommonAncestor(root->right, o1, o2);
        // 左子树找到了o1或o2，且右子树也找到了o1或o2，然后root即为最近公共父节点
        if (left != -1 && right != -1)         
            return root->val;    
        if (left == -1)     // 左边找到，肯定两个都在右边
            return right;
        return left;        // 否则相反
    }
};