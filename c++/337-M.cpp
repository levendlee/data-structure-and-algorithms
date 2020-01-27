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
    pair<int,int> preOrder(TreeNode* root) {
        if (!root) return {0, 0};
        auto l_ret = preOrder(root->left);
        auto r_ret = preOrder(root->right);
        auto taken = l_ret.second + r_ret.second + root->val; // subtrees roots must not taken
        auto not_taken = std::max(l_ret.first, l_ret.second) + std::max(r_ret.first, r_ret.second);
        return {taken, not_taken};
    }

public:
    int rob(TreeNode* root) {
        auto ret = preOrder(root);
        return std::max(ret.first, ret.second);
    }
};