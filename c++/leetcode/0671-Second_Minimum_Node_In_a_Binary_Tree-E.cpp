// 671 Second Minimum Node In a Binary Tree
// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree

// version: 1; create time: 2020-02-09 22:35:43;
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
    int min_;
    int second_min_;
    bool second_min_set_;

    void preOrder(TreeNode* root) {
        if (!root) return;
        if (root->val != min_) {
            second_min_set_ = true;
            second_min_ = std::min(second_min_, root->val);
            return;
        }
        preOrder(root->left);
        preOrder(root->right);
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        min_ = root->val;
        second_min_ = INT_MAX;
        second_min_set_ = false;
        preOrder(root);
        return !second_min_set_ ? -1 : second_min_;
    }
};
