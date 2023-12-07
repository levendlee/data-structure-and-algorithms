class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());

        vector<TreeNode*> res;
        function<void(TreeNode*&)> dfs;
        dfs = [&](TreeNode*& node) {
            if (!node) return;
            dfs(node->left);
            dfs(node->right);
            if (to_delete_set.count(node->val)) {
                if (node->left) res.push_back(node->left);
                if (node->right) res.push_back(node->right);
                node = nullptr;
            }
        };
        dfs(root);

        if (root) res.push_back(root);

        return res;
    }
};
