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
public:
    TreeNode* deleteNode(TreeNode*& root, int key) {
        if (!root) {
            return nullptr;
        }
        if (root->val == key) {
            auto tmp = root;
            if (!root->left) {
                root = root->right;
            } else if (!root->right) {
                root = root->left;
            } else {
                auto node = root->right;
                while (node->left) {
                    node = node->left;
                }
                node->left = root->left;
                root = root->right;
            }
            delete tmp;
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right =  deleteNode(root->right, key);
        }
        return root;
    }
};