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
    int longest_;

    vector<int> postOrder(TreeNode* root) {
        if (!root) return {0, 0};
        int increase = 1;
        int decrease = 1;
        auto update_child = [&](TreeNode* child) {
            if (child) {
                auto res = postOrder(child);
                if (child->val == root->val + 1) {
                    increase = std::max(res[0] + 1, increase);
                } else if (child->val == root->val - 1) {
                    decrease = std::max(res[1] + 1, decrease);
                }
            }
        };

        update_child(root->left);
        update_child(root->right);
        longest_ = std::max(increase + decrease - 1, longest_);
        return {increase, decrease};
    }
public:
    int longestConsecutive(TreeNode* root) {
        longest_ = 0;
        postOrder(root);
        return longest_;
    }
};