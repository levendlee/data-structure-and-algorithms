// 572 Subtree of Another Tree
// https://leetcode.com/problems/subtree-of-another-tree

// version: 1; create time: 2019-12-30 11:34:15;
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
    bool isSame(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        return s->val == t->val && isSame(s->left, t->left) && isSame(s->right, t->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (isSame(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t)) return true;
        return false;
    }
};
