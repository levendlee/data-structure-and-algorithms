// 865 Smallest Subtree with all the Deepest Nodes
// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes

// version: 1; create time: 2020-02-07 21:50:56;
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
    pair<TreeNode*, int> postOrder(TreeNode* root, int depth) {
        if (!root) return {nullptr, depth - 1};
        auto l_res = postOrder(root->left, depth + 1);
        auto r_res = postOrder(root->right, depth + 1);
        if (l_res.second > r_res.second) {
            return l_res;
        } else if (l_res.second < r_res.second) {
            return r_res;
        } else {
            return {root, l_res.second};
        }
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return postOrder(root, 0).first;
    }
};
