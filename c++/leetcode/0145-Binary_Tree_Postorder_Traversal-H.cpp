// 145 Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal

// version: 1; create time: 2020-02-02 17:12:27;
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;

        stack<pair<TreeNode*, bool>> stk;
        TreeNode* node = root;
        while (!stk.empty() || node) {
            if (node) {
                stk.push({node, false});
                node = node->left;
            } else {
                while (!stk.empty() && stk.top().second) {
                    res.push_back(stk.top().first->val); stk.pop();
                }
                if (stk.empty()) break;
                node = stk.top().first; stk.top().second = true;
                node = node->right;
            }
        }

        return res;
    }
};
