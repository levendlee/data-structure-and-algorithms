// 1120 Maximum Average Subtree
// https://leetcode.com/problems/maximum-average-subtree

// version: 1; create time: 2020-01-19 22:13:57;
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
    double max_avg_;

public:
    pair<int, int> postOrder(TreeNode* root) {
        if (!root) return {0, 0};
        auto lhs = postOrder(root->left);
        auto rhs = postOrder(root->right);
        int sum = root->val + lhs.first + rhs.first;
        int cnt = 1 + lhs.second + rhs.second;
        double avg = 1.0 * sum / cnt;
        max_avg_ = std::max(max_avg_, avg);
        return {sum, cnt};
    }

    double maximumAverageSubtree(TreeNode* root) {
        max_avg_ = std::numeric_limits<double>::min();
        postOrder(root);
        return max_avg_;
    }
};
