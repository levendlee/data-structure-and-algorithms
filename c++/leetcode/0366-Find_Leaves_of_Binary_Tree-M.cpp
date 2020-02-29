// 366 Find Leaves of Binary Tree
// https://leetcode.com/problems/find-leaves-of-binary-tree

// version: 1; create time: 2020-02-08 21:06:19;
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
    vector<vector<int>> finding_;

    int postOrder(TreeNode* root) {
        if (!root) return 0;
        auto lh = postOrder(root->left);
        auto rh = postOrder(root->right);
        auto h = std::max(lh, rh);
        if (finding_.size() <= h) {
            finding_.resize(h + 1);
        }
        finding_[h].push_back(root->val);
        return h + 1;
    }

public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        postOrder(root);
        return finding_;
    }
};
