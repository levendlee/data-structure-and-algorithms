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
    vector<int> res_;

    void preOrder(TreeNode* root, int depth) {
        if (!root) return;
        if (res_.size() <= depth) {
            res_.push_back(root->val);
        } else {
            res_[depth] = std::max(res_[depth], root->val);
        }
        preOrder(root->left, depth + 1);
        preOrder(root->right, depth + 1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        preOrder(root, 0);
        return res_;
    }
};