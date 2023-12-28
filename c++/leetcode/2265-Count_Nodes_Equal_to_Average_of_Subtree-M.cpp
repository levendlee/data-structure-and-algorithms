class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        function<pair<int, int>(TreeNode*)> dfs;
        dfs = [&](TreeNode* node) -> pair<int, int> {
            if (!node) return {0, 0};
            int sum = node->val, cnt = 1;
            auto [lsum, lcnt] = dfs(node->left);
            auto [rsum, rcnt] = dfs(node->right);
            sum += lsum + rsum;
            cnt += lcnt + rcnt;
            if (sum / cnt == node->val) {
                ++res;
            }
            return {sum, cnt};
        };
        dfs(root);
        return res;
    }
};
