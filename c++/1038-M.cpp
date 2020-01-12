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
    void reverseOrder(TreeNode* root, int& sum) {
        if (!root) return;
        reverseOrder(root->right, sum);
        root->val = sum += root->val;
        reverseOrder(root->left, sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        reverseOrder(root, sum);
        return root;
    }
};