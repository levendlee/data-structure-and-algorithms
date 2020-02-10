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
    int k_;
    int idx_;
    int kth_;

    bool inOrder(TreeNode* root) {
        if (!root) return false;
        if (inOrder(root->left)) return true;
        if (++idx_ == k_) {
            kth_ = root->val;
            return true;
        }
        if (inOrder(root->right)) return true;
        return false;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        k_ = k;
        idx_ = 0;
        kth_ = 0;
        inOrder(root);
        return kth_;
    }
};