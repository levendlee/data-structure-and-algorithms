class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> sums;
        function<void(TreeNode*, int)> dfs;
        dfs = [&](TreeNode* node, int level) {
            if (!node) return;

            if (sums.size() < level) {
                sums.push_back(0);
            }
            sums[level - 1] += node->val;
            dfs(node->left, level + 1);
            dfs(node->right, level + 1);
        };
        dfs(root, 1);

        int max_idx = max_element(sums.begin(), sums.end()) - sums.begin();
        return max_idx + 1;
    }
};
