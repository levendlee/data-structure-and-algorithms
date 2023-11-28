class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        function<pair<TreeNode*, int>(TreeNode*, int)> dfs;
        dfs = [&](TreeNode* node, int depth) -> pair<TreeNode*, int> {
            if (!node) return {node, depth};
            auto [l_lca, l_depth] = dfs(node->left, depth + 1);
            auto [r_lca, r_depth] = dfs(node->right, depth + 1);
            if (l_depth == r_depth) {
                return {node, l_depth};
            } else if (l_depth > r_depth) {
                return {l_lca, l_depth};
            } else {
                return {r_lca, r_depth};
            }
        };
        return dfs(root, 0).first;
    }
};
