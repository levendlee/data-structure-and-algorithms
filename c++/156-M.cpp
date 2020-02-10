/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* transform(TreeNode* root) {
        if (!root) return nullptr;
        if (!root->left && !root->right) return root;
        auto new_root = transform(root->left);
        root->left->left = root->right;
        root->left->right = root;
        root->left = nullptr;
        root->right = nullptr;
        return new_root;
    }
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        return transform(root);
    }
};