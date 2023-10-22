class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;

        function<void(TreeNode*, int)> traverse;
        traverse = [&](TreeNode* node, int level) {
            if (!node) return;
            if (view.size() < level) {
                view.push_back(node->val);
            }
            traverse(node->right, level + 1);
            traverse(node->left, level + 1);
        };
        traverse(root, 1);

        return view;
    }
};
