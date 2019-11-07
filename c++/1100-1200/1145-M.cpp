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
    bool win_;

public:
    int postOrder(TreeNode* root, int n, int x) {
        if (!root) return 0;
        if (win_) return 0; // no long matters
        int lcnt = postOrder(root->left, n, x);
        int rcnt = postOrder(root->right, n, x);
        if (root->left && root->left->val == x) {
            if (n - lcnt > lcnt) {
                win_ = true;
            }
        }
        else if (root->right && root->right->val == x) {
            if (n - rcnt > rcnt) {
                win_ = true;
            }
        }
        else if (root->val == x) {
            if (lcnt > n - lcnt || rcnt > n - rcnt) {
                win_ = true;
            }
        }
        return lcnt + rcnt + 1;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        win_ = false;
        postOrder(root, n, x);
        return win_;
    }
};