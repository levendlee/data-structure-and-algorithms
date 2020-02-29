// 94 Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal

// version: 1; create time: 2020-02-02 16:50:43;
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (!stk.empty() || node) {
            if (node) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top(); stk.pop();
                res.push_back(node->val);
                node = node->right;
            }
        }

        return res;
    }
};
