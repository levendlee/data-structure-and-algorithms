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