// 144 Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal

// version: 1; create time: 2020-02-02 16:54:25;
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;

        stack<TreeNode*> stk;
        TreeNode* node = root;

        while (!stk.empty() || node) {
            if (node) {
                res.push_back(node->val);
                stk.push(node->right);
                node = node->left;
            } else {
                node = stk.top(); stk.pop();
            }
        }

        return res;
    }
};
