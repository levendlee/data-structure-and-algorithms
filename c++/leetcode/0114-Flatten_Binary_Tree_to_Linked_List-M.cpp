class Solution {
public:
    void flatten(TreeNode* root) {
        function<TreeNode*(TreeNode*)> traverse;

        traverse = [&](TreeNode* node) {
            auto left = node->left, right = node->right;

            if (left) {
                node->left = nullptr;
                node->right = left;
                node = traverse(left);
            }
            if (right) {
                node->left = nullptr;
                node->right = right;
                node = traverse(right);
            }
            return node;
        };

        if (!root) return;
        traverse(root);
    }
};
