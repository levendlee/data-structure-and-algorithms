class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        auto tmp_l = invertTree(root->left);
        auto tmp_r = invertTree(root->right);
        root->left = tmp_r;
        root->right = tmp_l;
        return root;
    }
};
