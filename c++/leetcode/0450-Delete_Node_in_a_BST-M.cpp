// 450 Delete Node in a BST
// https://leetcode.com/problems/delete-node-in-a-bst

// version: 1; create time: 2019-12-26 14:08:57;
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

//

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        function<void(TreeNode*&)> dfs;

        dfs = [&](TreeNode*& root) {
            if (!root) return;
            if (key < root->val) {
                dfs(root->left);
            } else if (key > root->val) {
                dfs(root->right);
            } else {
                if (root->right) {
                    TreeNode* pre = root;
                    TreeNode* node = root->right;
                    while (node) {
                        pre = node;
                        node = node->left;
                    }
                    pre->left = root->left;
                    root = root->right;
                } else if (root->left) {
                    TreeNode* pre = root;
                    TreeNode* node = root->left;
                    while (node) {
                        pre = node;
                        node = node->right;
                    }
                    pre->right = root->right;
                    root = root->left;
                } else {
                    root = nullptr;
                }
            }
        };

        dfs(root);
        return root;
    }
};
