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
public:
    int longestUnivaluePath(TreeNode* root) {
        int longest_unival = 0;
        function<int(TreeNode*)> dfs;
        dfs = [&](TreeNode* node) -> int {
            if (!node) {
                return 0;
            }
            int lp = 0, rp = 0;
            if (node->left) {
                int p = dfs(node->left);
                if (node->left->val == node->val) lp = p;
            }
            if (node->right) {
                int p = dfs(node->right);
                if (node->right->val == node->val) rp = p;
            }
            longest_unival = max(longest_unival, lp + rp + 1);
            return max(lp, rp) + 1;
        };
        dfs(root);
        return max(longest_unival - 1, 0);
    }
};