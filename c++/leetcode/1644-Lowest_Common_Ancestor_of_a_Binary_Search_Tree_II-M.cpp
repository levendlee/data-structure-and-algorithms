class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = nullptr;
        function<int(TreeNode*)> dfs;
        dfs = [&](TreeNode* node) {
            if (!node) return 0;
            int mask = 0;
            if (node == p) mask |= 1;
            else if (node == q) mask |= 2;
            mask |= dfs(node->left);
            mask |= dfs(node->right);
            if (!lca && mask == 3) {
                lca = node;
            }
            return mask;
        };
        dfs(root);
        return lca;
    }
};
