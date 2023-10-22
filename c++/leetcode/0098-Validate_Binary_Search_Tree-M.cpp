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


// 2023/10/21
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        function<bool(TreeNode*, long long, long long)> traverse;

        traverse = [&](TreeNode* node, long long min_val, long long max_val) {
            if (!node) return true;
            if (node->val < min_val || node->val > max_val) return false;
            if (!traverse(node->left, min_val, node->val - 1LL)) return false;
            if (!traverse(node->right, node->val + 1LL, max_val)) return false;
            return true;
        };

        return traverse(root, INT_MIN, INT_MAX);
    }
};
