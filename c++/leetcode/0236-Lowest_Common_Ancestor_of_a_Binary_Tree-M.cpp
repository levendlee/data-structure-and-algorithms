// 236 Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

// version: 1; create time: 2020-01-18 18:42:35;
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
private:
    TreeNode* lca_;

    int postOrder(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0;
        auto lstatus = postOrder(root->left, p, q);
        if (lca_) return lstatus;
        auto rstatus = postOrder(root->right, p, q);
        if (lca_) return rstatus;
        auto status = lstatus | rstatus;
        if (root == p) status |= 0x1;
        if (root == q) status |= 0x2;
        if (!lca_ && status == 0x3) lca_ = root;
        return status;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca_ = nullptr;
        postOrder(root, p, q);
        return lca_;
    }
};
