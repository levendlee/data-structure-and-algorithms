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
public:
    pair<int,int> depthAndDiameter(TreeNode* root) {
        if (!root) return {0, 0};
        auto ldd = depthAndDiameter(root->left);
        auto rdd = depthAndDiameter(root->right);
        auto depth = std::max(ldd.first, rdd.first) + 1;
        auto diameter = std::max(std::max(ldd.second, rdd.second), ldd.first + rdd.first);
        return {depth, diameter};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return depthAndDiameter(root).second;
    }
};