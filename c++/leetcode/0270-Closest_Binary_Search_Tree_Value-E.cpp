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

//

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int closest_val = INT_MIN;
        double closest_diff = INT_MAX;

        auto node = root;
        while (node) {
            int cur_val = node->val;
            double cur_diff = abs(target - node->val);
            if ((cur_diff < closest_diff) || (cur_diff == closest_diff) && (cur_val < closest_val)) {
                closest_val = cur_val;
                closest_diff = cur_diff;
            }
            if (node->val >= target) {
                node = node->left;
            } else {
                node = node->right;
            }
        };

        return closest_val;
    }
};
