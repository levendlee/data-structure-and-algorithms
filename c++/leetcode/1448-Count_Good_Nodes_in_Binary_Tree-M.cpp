/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int cnt;
    
public:
    void helper(TreeNode* root, int maximum) {
        if (!root) return;
        if (root->val >= maximum) {
            cnt++;
        }
        maximum = max(root->val, maximum);
        helper(root->left, maximum);
        helper(root->right, maximum);
    }
    
    int goodNodes(TreeNode* root) {
        cnt = 0;
        helper(root, INT_MIN);
        return cnt;
    }
};
