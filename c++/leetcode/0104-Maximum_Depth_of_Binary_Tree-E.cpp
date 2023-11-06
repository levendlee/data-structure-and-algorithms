class Solution {
public:
    int maxDepth(TreeNode* root) {
        function<int(TreeNode*)> dfs;
        dfs = [&](TreeNode* root) {
            if (!root) return 0;
            return max(dfs(root->left), dfs(root->right)) + 1;
        };
        return dfs(root);
    }
};
