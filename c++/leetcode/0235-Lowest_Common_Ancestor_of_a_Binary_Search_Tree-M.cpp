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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = nullptr;
        function<int(TreeNode*)> dfs;
        dfs = [&](TreeNode* node) {
            if (!node) return 0;
            int mask = 0;
            if (node == p) mask |= 1;
            if (node == q) mask |= 2;
            mask |= dfs(node->left);
            if (lca) return 3;
            mask |= dfs(node->right);
            if (lca) return 3;
            if (mask == 3) {
                lca = node;
            }
            return mask;
        };
        dfs(root);
        return lca;
    }
};