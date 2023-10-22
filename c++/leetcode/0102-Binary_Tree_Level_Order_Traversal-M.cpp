class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        function<void(TreeNode*, int)> traverse;
        traverse = [&](TreeNode* node, int level) {
            if (!node) return;
            if (res.size() < level) {
                res.push_back({node->val});
            } else {
                res[level - 1].push_back(node->val);
            }
            traverse(node->left, level + 1);
            traverse(node->right, level + 1);
        };
        traverse(root, 1);

        return res;
    }
};
