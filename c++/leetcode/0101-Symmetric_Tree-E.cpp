class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        function<bool(TreeNode*, TreeNode*)> sym_match;

        sym_match = [&](TreeNode* l, TreeNode* r) {
            if (!l && !r) return true;
            if (!l || !r || l->val != r->val) return false;
            return sym_match(l->left, r->right) && sym_match(l->right, r->left);
        };

        return sym_match(root, root);
    }
};
