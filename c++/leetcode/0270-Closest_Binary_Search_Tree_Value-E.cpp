// 270 Closest Binary Search Tree Value
// https://leetcode.com/problems/closest-binary-search-tree-value

// version: 1; create time: 2020-02-07 20:23:52;
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
    double closest_;

    void updateClosest(double val, double target) {
        if (fabs(closest_ - target) > fabs(val - target)) {
            closest_ = val;
        }
    }

    void searchBST(TreeNode* root, double target) {
        if (!root) return;
        updateClosest(root->val, target);
        if (root->val == target) {
            closest_ = target;
        } else if (root->val > target) {
            searchBST(root->left, target);
        } else {
            searchBST(root->right, target);
        }
    }

public:

    int closestValue(TreeNode* root, double target) {
        closest_ = root->val;
        searchBST(root, target);
        return closest_;
    }
};
