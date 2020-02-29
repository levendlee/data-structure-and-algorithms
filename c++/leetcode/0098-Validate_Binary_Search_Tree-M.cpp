// 98 Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree

// version: 1; create time: 2020-01-12 11:55:51;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct CheckResult {
    bool success;
    int max;
    int min;
};

class Solution {
public:
    CheckResult isValidBSTHelper(TreeNode* root) {
        int local_max = root->val;
        int local_min = root->val;
        if (root->left) {
            auto result = isValidBSTHelper(root->left);
            if (!result.success || result.max >= root->val) return {false, 0, 0};
            local_min = result.min;
        }
        if (root->right) {
            auto result = isValidBSTHelper(root->right);
            if (!result.success || result.min <= root->val) return {false, 0, 0};
            local_max = result.max;
        }
        return {true, local_max, local_min};
    }

    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return isValidBSTHelper(root).success;
    }
};
