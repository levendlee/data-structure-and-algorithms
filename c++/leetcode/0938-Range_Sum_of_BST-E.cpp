// 938 Range Sum of BST
// https://leetcode.com/problems/range-sum-of-bst

// version: 1; create time: 2020-02-07 21:36:43;
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
    int inOrder(TreeNode* root, int L, int R) {
        if (!root) return 0;
        int sum = root->val >= L && root->val <= R ? root->val : 0;
        if (root->val > L) sum += inOrder(root->left, L, R);
        if (root->val < R) sum += inOrder(root->right, L, R);
        return sum;
    }

public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        return inOrder(root, L, R);
    }
};
