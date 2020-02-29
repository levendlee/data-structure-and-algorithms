// 298 Binary Tree Longest Consecutive Sequence
// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence

// version: 1; create time: 2019-12-14 15:46:48;
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
    int max_len_;

public:
    void findConsecutive(TreeNode* root, int pval, int plen) {
        if (!root) return;
        int cnt = (root->val == pval + 1) ? (plen + 1) : 1;
        findConsecutive(root->left, root->val, cnt);
        findConsecutive(root->right, root->val, cnt);
        max_len_ = std::max(max_len_, cnt);
    }

    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        max_len_ = 0;
        findConsecutive(root, root->val, 1);
        return max_len_;
    }
};
