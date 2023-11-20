class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        function<int(TreeNode* root)> dfs;
        dfs = [&](TreeNode* node) {
            if (!node) return 0;
            if (node->val > high) {
                return dfs(node->left);
            } else if (node->val < low) {
                return dfs(node->right);
            } else {
                return dfs(node->left) + dfs(node->right) + node->val;
            }
        };
        return dfs(root);
    }
};
