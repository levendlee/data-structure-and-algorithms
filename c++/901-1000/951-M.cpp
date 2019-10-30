class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;
        if ((root1->left && root2->left && (root1->left->val == root2->left->val)) ||
            (!root1->left && !root2->left)) {
            return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        } else {
            return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        }
    }
};