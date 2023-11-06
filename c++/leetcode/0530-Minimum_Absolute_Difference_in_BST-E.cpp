class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int64_t min_diff = INT_MAX;
        
        function<void(TreeNode*, int64_t, int64_t)> dfs;
        dfs = [&](TreeNode* node, int64_t min_val, int64_t max_val) {
            if (!node) return;
            min_diff = min({node->val - min_val, max_val - node->val, min_diff});
            dfs(node->left, min_val, node->val);
            dfs(node->right, node->val, max_val);
        };
        dfs(root, INT_MIN, INT_MAX);

        return min_diff;
    }
};
