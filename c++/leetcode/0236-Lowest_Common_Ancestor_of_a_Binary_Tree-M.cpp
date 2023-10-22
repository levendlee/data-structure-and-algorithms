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

// 2023/10/21
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == q) return p;

        TreeNode* lca = nullptr;
        function<int(TreeNode*)> preorder;
        preorder = [&](TreeNode* node) {
            if (!node) return 0;
            int mask = 0;
            if (node == p) {
                mask |= 1;
            }
            if (node == q) {
                mask |= 2;
            }
            mask |= preorder(node->left);
            mask |= preorder(node->right);
            if (!lca && mask == 3) {
                lca = node;
            }
            return mask;
        };
        preorder(root);

        return lca;
    }
};
