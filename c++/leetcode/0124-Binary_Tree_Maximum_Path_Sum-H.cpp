class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_path_sum = INT_MIN;

        function<int(TreeNode*)> dfs;
        dfs = [&](TreeNode* node) {
            if (!node) return 0;
            int lsum = dfs(node->left);
            int rsum = dfs(node->right);
            int ret_max_sum = max({node->val, lsum + node->val, node->val + rsum});
            int cur_max_sum = max({ret_max_sum, lsum + node->val + rsum});
            max_path_sum = max(max_path_sum, cur_max_sum);
            return ret_max_sum;
        };

        dfs(root);
        return max_path_sum;
    }
};
