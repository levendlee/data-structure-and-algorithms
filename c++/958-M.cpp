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
    bool complete_;

public:
    pair<int, int> inOrderTraversal(TreeNode* node, int depth) {
        if (!node) return {depth, depth};
        auto ld = inOrderTraversal(node->left, depth + 1);
        auto rd = inOrderTraversal(node->right, depth + 1);
        if ((ld.second < rd.first) || (ld.first > rd.second + 1)) complete_ = false;
        return {ld.first, rd.second};
    }

    bool isCompleteTree(TreeNode* root) {
        complete_ = true;
        inOrderTraversal(root, 0);
        return complete_;
    }
};