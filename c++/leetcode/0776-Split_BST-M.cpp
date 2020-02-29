// 776 Split BST
// https://leetcode.com/problems/split-bst

// version: 1; create time: 2019-12-26 11:35:06;
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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if (!root) return {nullptr, nullptr};

        std::stack<TreeNode*> stk;
        stk.push(root);

        TreeNode* max_node = nullptr;
        while (!stk.empty()) {
            const auto node = stk.top();
            if (node->val == V) {
                max_node = node;
                if (!node->right) break;
                stk.push(node->right);
            } else if (node->val > V) {
                if (!node->left) break;
                stk.push(node->left);
            } else {
                max_node = (max_node && max_node->val > node->val) ? max_node : node;
                if (!node->right) break;
                stk.push(node->right);
            }
        }

        TreeNode* large_root = nullptr;
        TreeNode* small_root = nullptr;
        while (!stk.empty()) {
            TreeNode* node = stk.top(); stk.pop();
            if (node->val <= V) {
                if (node->right == large_root) {
                    node->right = small_root;
                }
                small_root = node;
            } else {
                if (node->left == small_root) {
                    node->left = large_root;
                }
                large_root = node;
            }
        }

        return {small_root, large_root};
    }
};
