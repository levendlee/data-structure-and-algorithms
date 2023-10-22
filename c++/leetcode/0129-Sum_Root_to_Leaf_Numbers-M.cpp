// 129 Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers

// version: 1; create time: 2020-02-10 14:18:10;
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
    int preOrder(TreeNode* root, int prefix) {
        if (!root) return 0;
        int nprefix = prefix * 10 + root->val;
        if (!root->left && !root->right) return nprefix;
        return preOrder(root->left, nprefix) + preOrder(root->right, nprefix);
    }

public:
    int sumNumbers(TreeNode* root) {
        return preOrder(root, 0);
    }
};

// 2023/10/21

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;

        function<void(TreeNode*, int)> preorder;
        preorder = [&](TreeNode* root, int val) {
            val = val * 10 + root->val;
            if (!root->left && !root->right) {
                sum += val;
            } 
            if (root->left) {
                preorder(root->left, val);
            }
            if (root->right) {
                preorder(root->right, val);
            }
        };
        preorder(root, 0);

        return sum;
    }
};
